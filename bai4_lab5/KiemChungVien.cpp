#include "KiemChungVien.h"
using namespace std;

void KiemChungVien::Nhap() {
  cout << "\n--- Nhập Thông Tin Kiểm Chứng Viên ---\n";
  NhanVien::Nhap();
  do {
    cout << "Nhập số lỗi phát hiện: ";
    cin >> soLoi;
    if (soLoi < 0) cout << "Lỗi: Số lỗi không được âm!\n";
  } while (soLoi < 0);
}

void KiemChungVien::Xuat() const {
  cout << "[KCV] ";
  NhanVien::Xuat();
  cout << " | Số lỗi: " << soLoi << "\n";
}

void KiemChungVien::TinhLuong() {
  luongHangThang = luongCoBan + (soLoi * 50000);
}