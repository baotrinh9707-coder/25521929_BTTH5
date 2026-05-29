#include "GiaoDichDat.h"
using namespace std;

void GiaoDichDat::Nhap() {
  cout << "--- Nhập Giao Dịch Đất ---\n";
  GiaoDich::Nhap();
  cout << "Nhập loại đất (A/B/C): ";
  cin >> loaiDat;
}
void GiaoDichDat::Xuat() const {
  cout << "[ĐẤT] ";
  GiaoDich::Xuat();
  cout << " | Loại: " << loaiDat << "\n";
}
void GiaoDichDat::TinhThanhTien() {
  if (loaiDat == "A" || loaiDat == "a")
    thanhTien = dienTich * donGia * 1.5;
  else
    thanhTien = dienTich * donGia;  // Loại B, C
}