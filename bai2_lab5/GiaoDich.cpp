#include "GiaoDich.h"

#include <limits>

using namespace std;

GiaoDich::GiaoDich() : donGia(0), dienTich(0), thanhTien(0) {}
GiaoDich::~GiaoDich() {}

void GiaoDich::Nhap() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập mã giao dịch: ";
  getline(cin, maGiaoDich);
  cout << "Nhập ngày giao dịch (ngay thang nam): ";
  cin >> ngayGiaoDich.ngay >> ngayGiaoDich.thang >> ngayGiaoDich.nam;
  cout << "Nhập đơn giá: ";
  cin >> donGia;
  cout << "Nhập diện tích: ";
  cin >> dienTich;
}

void GiaoDich::Xuat() const {
  cout << "Mã GD: " << maGiaoDich << " | Ngày: " << ngayGiaoDich.ngay << "/"
       << ngayGiaoDich.thang << "/" << ngayGiaoDich.nam
       << " | Đơn giá: " << (long long)donGia << " | Diện tích: " << dienTich
       << " | Thành tiền: " << (long long)thanhTien;
}

double GiaoDich::GetThanhTien() const { return thanhTien; }
int GiaoDich::GetThang() const { return ngayGiaoDich.thang; }
int GiaoDich::GetNam() const { return ngayGiaoDich.nam; }