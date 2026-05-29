#include "NhanVien.h"

#include <limits>

using namespace std;

NhanVien::NhanVien() : tuoi(0), luongCoBan(0), luongHangThang(0) {}
NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập Mã NV: ";
  getline(cin, maNV);
  cout << "Nhập Họ tên: ";
  getline(cin, hoTen);

  do {
    cout << "Nhập Tuổi (tuổi > 0): ";
    cin >> tuoi;
    if (tuoi <= 0) cout << "Lỗi: Tuổi phải là số dương!\n";
  } while (tuoi <= 0);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập SĐT: ";
  getline(cin, sdt);
  cout << "Nhập Email: ";
  getline(cin, email);

  do {
    cout << "Nhập Lương cơ bản: ";
    cin >> luongCoBan;
    if (luongCoBan < 0) cout << "Lỗi: Lương cơ bản không được âm!\n";
  } while (luongCoBan < 0);
}

void NhanVien::Xuat() const {
  cout << "Mã NV: " << maNV << " | Tên: " << hoTen << " | Tuổi: " << tuoi
       << " | Lương CB: " << (long long)luongCoBan
       << " | Tổng Lương: " << (long long)luongHangThang << " VND";
}

double NhanVien::GetLuong() const { return luongHangThang; }