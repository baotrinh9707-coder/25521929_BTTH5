#include "LapTrinhVien.h"
using namespace std;

void LapTrinhVien::Nhap() {
  cout << "\n--- Nhập Thông Tin Lập Trình Viên ---\n";
  NhanVien::Nhap();
  do {
    cout << "Nhập số giờ overtime: ";
    cin >> soGioOvertime;
    if (soGioOvertime < 0) cout << "Lỗi: Số giờ overtime không được âm!\n";
  } while (soGioOvertime < 0);
}

void LapTrinhVien::Xuat() const {
  cout << "[LTV] ";
  NhanVien::Xuat();
  cout << " | OT: " << soGioOvertime << "h\n";
}

void LapTrinhVien::TinhLuong() {
  luongHangThang = luongCoBan + (soGioOvertime * 200000);
}