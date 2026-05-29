#pragma once
#include "NhanVien.h"

class NhanVienVanPhong : public NhanVien {
 private:
  int soNgayLamViec;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhLuong() override;
};