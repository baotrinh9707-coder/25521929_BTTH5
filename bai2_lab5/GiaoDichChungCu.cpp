#include "GiaoDichChungCu.h"
using namespace std;

void GiaoDichChungCu::Nhap() {
  cout << "--- Nhập Giao Dịch Chung Cư ---\n";
  GiaoDich::Nhap();
  cout << "Nhập mã căn: ";
  cin >> maCan;
  cout << "Nhập vị trí tầng: ";
  cin >> viTriTang;
}
void GiaoDichChungCu::Xuat() const {
  cout << "[CHUNG CƯ] ";
  GiaoDich::Xuat();
  cout << " | Mã căn: " << maCan << " | Tầng: " << viTriTang << "\n";
}
void GiaoDichChungCu::TinhThanhTien() {
  if (viTriTang == 1)
    thanhTien = dienTich * donGia * 2;
  else if (viTriTang >= 15)
    thanhTien = dienTich * donGia * 1.2;
  else
    thanhTien = dienTich * donGia;
}