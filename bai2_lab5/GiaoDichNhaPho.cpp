#include "GiaoDichNhaPho.h"

#include <limits>
using namespace std;

void GiaoDichNhaPho::Nhap() {
  cout << "--- Nhập Giao Dịch Nhà Phố ---\n";
  GiaoDich::Nhap();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập loại nhà (cao cap/thuong): ";
  getline(cin, loaiNha);
  cout << "Nhập địa chỉ: ";
  getline(cin, diaChi);
}
void GiaoDichNhaPho::Xuat() const {
  cout << "[NHÀ PHỐ] ";
  GiaoDich::Xuat();
  cout << " | Loại: " << loaiNha << " | Địa chỉ: " << diaChi << "\n";
}
void GiaoDichNhaPho::TinhThanhTien() {
  if (loaiNha == "cao cap" || loaiNha == "cao cấp")
    thanhTien = dienTich * donGia;
  else
    thanhTien = dienTich * donGia * 0.9;
}