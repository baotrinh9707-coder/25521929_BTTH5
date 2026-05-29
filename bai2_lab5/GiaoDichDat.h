#pragma once
#include "GiaoDich.h"

class GiaoDichDat : public GiaoDich {
 private:
  std::string loaiDat;  // "A", "B", "C"
 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhThanhTien() override;
};