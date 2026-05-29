#pragma once
#include "GiaoDich.h"

class GiaoDichNhaPho : public GiaoDich {
 private:
  std::string loaiNha;  // "cao cấp", "thường"
  std::string diaChi;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhThanhTien() override;
};