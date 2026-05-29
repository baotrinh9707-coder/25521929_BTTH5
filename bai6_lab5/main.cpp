#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ================= LỚP CƠ SỞ =================
class KhachHang {
protected:
    string tenKH;
    double soLuong;
    double donGia;
public:
    KhachHang() : soLuong(0), donGia(0) {}
    virtual ~KhachHang() {}

    // Hàm ảo đọc dữ liệu từ file
    virtual void Doc(ifstream& in) {
        in >> ws; // Bỏ qua các khoảng trắng thừa / ký tự xuống dòng
        getline(in, tenKH);
        in >> soLuong >> donGia;
    }

    // Hàm ảo ghi dữ liệu ra file
    virtual void Ghi(ofstream& out) {
        // Ép kiểu long long để in ra số nguyên, không bị dính số thập phân
        out << tenKH << "\n" << (long long)TinhTien() << "\n";
    }

    // Hàm thuần ảo tính tiền
    virtual double TinhTien() = 0;
};

// ================= CÁC LỚP DẪN XUẤT =================
class KhachHangA : public KhachHang {
public:
    double TinhTien() override {
        // Giá gốc + 10% VAT
        return (soLuong * donGia) * 1.1;
    }
};

class KhachHangB : public KhachHang {
private:
    int soNamThanThiet;
public:
    void Doc(ifstream& in) override {
        KhachHang::Doc(in);
        in >> soNamThanThiet;
    }

    double TinhTien() override {
        // Sử dụng min để khống chế khuyến mãi tối đa là 50% (0.5)
        double phanTramKM = min(soNamThanThiet * 0.05, 0.50);
        
        // (Số lượng * Đơn giá) * (100% - Khuyến mãi) + 10% VAT
        return (soLuong * donGia) * (1.0 - phanTramKM) * 1.1;
    }
};

class KhachHangC : public KhachHang {
public:
    double TinhTien() override {
        // Giảm 50% (tức là nhân 0.5) + 10% VAT
        return (soLuong * donGia) * 0.5 * 1.1;
    }
};

// ================= HÀM MAIN =================
int main() {
    // Mở file để Đọc và Ghi
    ifstream inFile("XYZ.INP");
    ofstream outFile("XYZ.OUT");

    if (!inFile.is_open()) {
        cout << "Lỗi: Không tìm thấy file XYZ.INP để đọc!\n";
        return 0;
    }

    int x, y, z;
    // Đọc dòng đầu tiên chứa x y z
    if (!(inFile >> x >> y >> z)) return 0;

    vector<KhachHang*> danhSach;

    // 1. Đọc x khách hàng loại A
    for (int i = 0; i < x; ++i) {
        KhachHang* kh = new KhachHangA();
        kh->Doc(inFile);
        danhSach.push_back(kh);
    }

    // 2. Đọc y khách hàng loại B
    for (int i = 0; i < y; ++i) {
        KhachHang* kh = new KhachHangB();
        kh->Doc(inFile);
        danhSach.push_back(kh);
    }

    // 3. Đọc z khách hàng loại C
    for (int i = 0; i < z; ++i) {
        KhachHang* kh = new KhachHangC();
        kh->Doc(inFile);
        danhSach.push_back(kh);
    }

    // 4. Ghi dữ liệu ra file XYZ.OUT
    outFile << x << " " << y << " " << z << "\n";
    
    double tongTienCongTy = 0;
    for (KhachHang* kh : danhSach) {
        kh->Ghi(outFile);
        tongTienCongTy += kh->TinhTien();
    }
    
    // Ghi tổng tiền công ty thu được ở dòng cuối
    outFile << (long long)tongTienCongTy << "\n";

    // 5. Dọn dẹp bộ nhớ và đóng file
    for (KhachHang* kh : danhSach) {
        delete kh;
    }
    inFile.close();
    outFile.close();

    cout << "Da xu ly xong! Kiem tra file XYZ.OUT nhe.\n";
    return 0;
}