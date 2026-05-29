#pragma once
#include <iostream>
#include <string>

struct NgayGiaoDich {
  int ngay, thang, nam;
};

class GiaoDich {
 protected:
  std::string maGiaoDich;
  NgayGiaoDich ngayGiaoDich;
  double donGia;
  double dienTich;
  double thanhTien;

 public:
  GiaoDich();
  virtual ~GiaoDich();

  virtual void Nhap();
  virtual void Xuat() const;
  virtual void TinhThanhTien() = 0;  // Thuần ảo

  double GetThanhTien() const;
  int GetThang() const;
  int GetNam() const;
};