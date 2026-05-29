#include "SinhVien.h"

#include <limits>

using namespace std;

SinhVien::SinhVien() : tongTinChi(0), diemTB(0.0) {}
SinhVien::~SinhVien() {}

void SinhVien::Nhap() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Nhập MSSV: ";
  getline(cin, maSV);
  cout << "Nhập Họ tên: ";
  getline(cin, hoTen);
  cout << "Nhập Địa chỉ: ";
  getline(cin, diaChi);
  cout << "Nhập Tổng tín chỉ: ";
  cin >> tongTinChi;
  cout << "Nhập Điểm trung bình: ";
  cin >> diemTB;
}

void SinhVien::Xuat() const {
  cout << "MSSV: " << maSV << " | Tên: " << hoTen
       << " | Tín chỉ: " << tongTinChi << " | ĐTB: " << diemTB;
}

double SinhVien::GetDiemTB() const { return diemTB; }