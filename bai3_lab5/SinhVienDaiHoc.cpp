#include "SinhVienDaiHoc.h"

#include <limits>

using namespace std;

void SinhVienDaiHoc::Nhap() {
  cout << "--- Nhập Sinh viên Đại học ---\n";
  SinhVien::Nhap();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập Tên luận văn: ";
  getline(cin, tenLuanVan);
  cout << "Nhập Điểm luận văn: ";
  cin >> diemLuanVan;
}

void SinhVienDaiHoc::Xuat() const {
  cout << "[ĐH] ";
  SinhVien::Xuat();
  cout << " | Luận văn: " << tenLuanVan << " | Điểm LV: " << diemLuanVan
       << "\n";
}

bool SinhVienDaiHoc::XetTotNghiep() const {
  return (tongTinChi >= 170 && diemTB >= 5.0 && diemLuanVan >= 5.0);
}