#include <iostream>
#include <limits>
#include <vector>

#include "NhanVienSanXuat.h"
#include "NhanVienVanPhong.h"

using namespace std;

int main() {
  vector<NhanVien*> danhSach;
  int luaChon;

  do {
    cout << "\n1. Thêm NV Sản xuất\n2. Thêm NV Văn phòng\n0. Dừng\nChọn: ";
    cin >> luaChon;

    NhanVien* nv = nullptr;
    if (luaChon == 1) {
      nv = new NhanVienSanXuat();
    } else if (luaChon == 2) {
      nv = new NhanVienVanPhong();
    }

    if (nv != nullptr) {
      nv->Nhap();
      danhSach.push_back(nv);
    }
  } while (luaChon != 0);

  double tongLuong = 0;
  for (NhanVien* nv : danhSach) {
    nv->TinhLuong();
    tongLuong += nv->GetLuong();
  }

  cout << "\n===== DANH SÁCH NHÂN VIÊN =====\n";
  for (NhanVien* nv : danhSach) {
    nv->Xuat();
  }

  cout << "=> Tổng lương công ty: " << (long long)tongLuong << " VND\n";

  NhanVienSanXuat* nvSxLuongThapNhat = nullptr;
  NhanVienVanPhong* nvVpTuoiCaoNhat = nullptr;

  double minLuong = numeric_limits<double>::max();
  int minNamSinh = numeric_limits<int>::max();

  for (NhanVien* nv : danhSach) {
    if (NhanVienSanXuat* sx = dynamic_cast<NhanVienSanXuat*>(nv)) {
      if (sx->GetLuong() < minLuong) {
        minLuong = sx->GetLuong();
        nvSxLuongThapNhat = sx;
      }
    } else if (NhanVienVanPhong* vp = dynamic_cast<NhanVienVanPhong*>(nv)) {
      if (vp->GetNamSinh() < minNamSinh) {
        minNamSinh = vp->GetNamSinh();
        nvVpTuoiCaoNhat = vp;
      }
    }
  }

  cout << "\n===== THỐNG KÊ =====\n";
  if (nvSxLuongThapNhat) {
    cout << "NVSX lương thấp nhất:\n";
    nvSxLuongThapNhat->Xuat();
  }
  if (nvVpTuoiCaoNhat) {
    cout << "NVVP lớn tuổi nhất:\n";
    nvVpTuoiCaoNhat->Xuat();
  }

  for (NhanVien* nv : danhSach) {
    delete nv;
  }

  return 0;
}