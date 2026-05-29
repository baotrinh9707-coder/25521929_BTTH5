#pragma once
#include <iostream>
#include <string>

class SinhVien {
 protected:
  std::string maSV;
  std::string hoTen;
  std::string diaChi;
  int tongTinChi;
  double diemTB;

 public:
  SinhVien();
  virtual ~SinhVien();

  virtual void Nhap();
  virtual void Xuat() const;
  virtual bool XetTotNghiep() const = 0;  // Hàm thuần ảo trả về bool

  double GetDiemTB() const;
};