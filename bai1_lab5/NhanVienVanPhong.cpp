#include "NhanVienVanPhong.h"

using namespace std;

void NhanVienVanPhong::Nhap() {
  cout << "--- Nhập thông tin Nhân viên văn phòng ---" << endl;
  NhanVien::Nhap();
  cout << "Nhập số ngày làm việc: ";
  cin >> soNgayLamViec;
}

void NhanVienVanPhong::Xuat() const {
  cout << "[NVVP] ";
  NhanVien::Xuat();
  cout << " | Số ngày làm: " << soNgayLamViec << endl;
}

void NhanVienVanPhong::TinhLuong() { luong = soNgayLamViec * 100000; }