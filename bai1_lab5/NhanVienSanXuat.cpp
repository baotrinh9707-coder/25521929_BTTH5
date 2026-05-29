#include "NhanVienSanXuat.h"

using namespace std;

void NhanVienSanXuat::Nhap() {
  cout << "--- Nhập thông tin Nhân viên sản xuất ---" << endl;
  NhanVien::Nhap();
  cout << "Nhập lương căn bản: ";
  cin >> luongCanBan;
  cout << "Nhập số sản phẩm: ";
  cin >> soSanPham;
}

void NhanVienSanXuat::Xuat() const {
  cout << "[NVSX] ";
  NhanVien::Xuat();
  cout << " | Lương CB: " << (long long)luongCanBan << " | Số SP: " << soSanPham
       << endl;
}

void NhanVienSanXuat::TinhLuong() { luong = luongCanBan + soSanPham * 5000; }