#pragma once
#include <iostream>
#include <string>

struct NgaySinh {
  int ngay, thang, nam;
};

class NhanVien {
 protected:
  std::string hoTen;
  NgaySinh ngaySinh;
  double luong;

 public:
  NhanVien();
  virtual ~NhanVien();

  virtual void Nhap();
  virtual void Xuat() const;
  virtual void TinhLuong() = 0;

  double GetLuong() const;
  int GetNamSinh() const;
};