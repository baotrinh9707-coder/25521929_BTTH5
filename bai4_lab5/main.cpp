#include <iostream>
#include <vector>

#include "KiemChungVien.h"
#include "LapTrinhVien.h"

using namespace std;

int main() {
  vector<NhanVien*> ds;
  int chon;

  // a. Nhập danh sách
  do {
    cout << "\n1. Lập trình viên | 2. Kiểm chứng viên | 0. Dừng\nChọn: ";
    cin >> chon;
    NhanVien* nv = nullptr;

    if (chon == 1)
      nv = new LapTrinhVien();
    else if (chon == 2)
      nv = new KiemChungVien();

    if (nv) {
      nv->Nhap();
      nv->TinhLuong();  // Tính lương ngay sau khi nhập
      ds.push_back(nv);
    }
  } while (chon != 0);

  if (ds.empty()) {
    cout << "Danh sách trống!\n";
    return 0;
  }

  // b. Xuất danh sách và Tính trung bình
  double tongLuongCongTy = 0;
  cout << "\n===== DANH SÁCH NHÂN VIÊN =====\n";
  for (NhanVien* nv : ds) {
    nv->Xuat();
    tongLuongCongTy += nv->GetLuong();
  }
  double luongTrungBinh = tongLuongCongTy / ds.size();
  cout << "=> Lương trung bình toàn công ty: " << (long long)luongTrungBinh
       << " VND\n";

  // Khởi tạo các biến thống kê
  NhanVien *nvMax = ds[0], *nvMin = ds[0];
  LapTrinhVien* ltvMax = nullptr;
  KiemChungVien* kcvMin = nullptr;
  double maxLTV = -1, minKCV = 1e18;  // 1e18 là 1 số cực lớn

  cout << "\n===== NV CÓ LƯƠNG THẤP HƠN TRUNG BÌNH =====\n";
  for (NhanVien* nv : ds) {
    // c. Lương thấp hơn trung bình
    if (nv->GetLuong() < luongTrungBinh) nv->Xuat();

    // d, e. Tích lũy tìm NV lương Max/Min toàn công ty
    if (nv->GetLuong() > nvMax->GetLuong()) nvMax = nv;
    if (nv->GetLuong() < nvMin->GetLuong()) nvMin = nv;

    // f, g. Tích lũy tìm LTV Max và KCV Min
    if (LapTrinhVien* ltv = dynamic_cast<LapTrinhVien*>(nv)) {
      if (ltv->GetLuong() > maxLTV) {
        maxLTV = ltv->GetLuong();
        ltvMax = ltv;
      }
    } else if (KiemChungVien* kcv = dynamic_cast<KiemChungVien*>(nv)) {
      if (kcv->GetLuong() < minKCV) {
        minKCV = kcv->GetLuong();
        kcvMin = kcv;
      }
    }
  }

  cout << "\n===== THỐNG KÊ CHI TIẾT =====\n";
  cout << "[NV lương CAO NHẤT] ";
  nvMax->Xuat();
  cout << "[NV lương THẤP NHẤT] ";
  nvMin->Xuat();

  if (ltvMax) {
    cout << "[LTV lương CAO NHẤT] ";
    ltvMax->Xuat();
  } else {
    cout << "Không có Lập trình viên nào.\n";
  }

  if (kcvMin) {
    cout << "[KCV lương THẤP NHẤT] ";
    kcvMin->Xuat();
  } else {
    cout << "Không có Kiểm chứng viên nào.\n";
  }

  // Dọn dẹp
  for (NhanVien* nv : ds) delete nv;
  return 0;
}