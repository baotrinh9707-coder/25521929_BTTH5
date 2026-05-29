#include "NhanVien.h"

#include <limits>

using namespace std;

NhanVien::NhanVien() : luong(0) {}

NhanVien::~NhanVien() {}

void NhanVien::Nhap() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập họ tên: ";
  getline(cin, hoTen);
  cout << "Nhập ngày sinh (ngay thang nam): ";
  cin >> ngaySinh.ngay >> ngaySinh.thang >> ngaySinh.nam;
}

void NhanVien::Xuat() const {
  cout << "Họ tên: " << hoTen << " | Ngày sinh: " << ngaySinh.ngay << "/"
       << ngaySinh.thang << "/" << ngaySinh.nam
       << " | Lương: " << (long long)luong << " VND";
}

double NhanVien::GetLuong() const { return luong; }

int NhanVien::GetNamSinh() const { return ngaySinh.nam; }