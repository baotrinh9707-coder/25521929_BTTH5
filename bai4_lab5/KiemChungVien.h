#pragma once
#include "NhanVien.h"

class KiemChungVien : public NhanVien {
 private:
  int soLoi;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhLuong() override;
};