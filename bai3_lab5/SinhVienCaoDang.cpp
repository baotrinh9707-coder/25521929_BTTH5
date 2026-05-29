#include "SinhVienCaoDang.h"

using namespace std;

void SinhVienCaoDang::Nhap() {
  cout << "--- Nhập Sinh viên Cao đẳng ---\n";
  SinhVien::Nhap();
  cout << "Nhập Điểm thi tốt nghiệp: ";
  cin >> diemThiTotNghiep;
}

void SinhVienCaoDang::Xuat() const {
  cout << "[CĐ] ";
  SinhVien::Xuat();
  cout << " | Điểm thi TN: " << diemThiTotNghiep << "\n";
}

bool SinhVienCaoDang::XetTotNghiep() const {
  return (tongTinChi >= 120 && diemTB >= 5.0 && diemThiTotNghiep >= 5.0);
}