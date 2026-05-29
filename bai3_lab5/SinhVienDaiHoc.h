#pragma once
#include "SinhVien.h"

class SinhVienDaiHoc : public SinhVien {
 private:
  std::string tenLuanVan;
  double diemLuanVan;

 public:
  void Nhap() override;
  void Xuat() const override;
  bool XetTotNghiep() const override;
};