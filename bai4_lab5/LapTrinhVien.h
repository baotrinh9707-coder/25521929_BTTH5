#pragma once
#include "NhanVien.h"

class LapTrinhVien : public NhanVien {
 private:
  int soGioOvertime;

 public:
  void Nhap() override;
  void Xuat() const override;
  void TinhLuong() override;
};