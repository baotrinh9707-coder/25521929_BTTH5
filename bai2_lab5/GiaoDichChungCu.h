#pragma once
#include "GiaoDich.h"

class GiaoDichChungCu : public GiaoDich {
 private:
  std::string maCan;
  int viTriTang;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhThanhTien() override;
};