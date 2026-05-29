#pragma once
#include "SinhVien.h"

class SinhVienCaoDang : public SinhVien {
 private:
  double diemThiTotNghiep;

 public:
  void Nhap() override;
  void Xuat() const override;
  bool XetTotNghiep() const override;
};