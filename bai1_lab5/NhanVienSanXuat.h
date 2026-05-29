#pragma once
#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien {
 private:
  double luongCanBan;
  int soSanPham;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhLuong() override;
};