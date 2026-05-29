#pragma once
#include <iostream>
#include <string>

class NhanVien {
protected:
  std::string maNV;
  std::string hoTen;
  int tuoi;
  std::string sdt;
  std::string email;
  double luongCoBan;
  double luongHangThang;

public:
  NhanVien();
  virtual ~NhanVien();

  virtual void Nhap();
  virtual void Xuat() const;
  virtual void TinhLuong() = 0; // Hàm thuần ảo

  double GetLuong() const;
};