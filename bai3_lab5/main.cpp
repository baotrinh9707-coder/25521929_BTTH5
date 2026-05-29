#include <iostream>
#include <vector>

#include "SinhVienCaoDang.h"
#include "SinhVienDaiHoc.h"

using namespace std;

int main() {
  vector<SinhVien*> ds;
  int chon;

  // a. Nhập danh sách sinh viên
  do {
    cout << "\n1. Thêm SV Cao đẳng | 2. Thêm SV Đại học | 0. Dừng\nChọn: ";
    cin >> chon;
    SinhVien* sv = nullptr;

    if (chon == 1)
      sv = new SinhVienCaoDang();
    else if (chon == 2)
      sv = new SinhVienDaiHoc();

    if (sv) {
      sv->Nhap();
      ds.push_back(sv);
    }
  } while (chon != 0);

  // b. Xuất danh sách
  cout << "\n===== DANH SÁCH SINH VIÊN =====\n";
  for (SinhVien* sv : ds) {
    sv->Xuat();
  }

  // c. Xuất danh sách đủ điều kiện tốt nghiệp
  cout << "\n===== ĐỦ ĐIỀU KIỆN TỐT NGHIỆP =====\n";
  for (SinhVien* sv : ds) {
    if (sv->XetTotNghiep()) sv->Xuat();
  }

  // d. Xuất danh sách không đủ điều kiện
  cout << "\n===== KHÔNG ĐỦ ĐIỀU KIỆN TỐT NGHIỆP =====\n";
  for (SinhVien* sv : ds) {
    if (!sv->XetTotNghiep()) sv->Xuat();
  }

  // e, f, g. Thống kê theo hệ
  double maxDiemTBDaiHoc = -1.0;
  double maxDiemTBCaoDang = -1.0;
  SinhVienDaiHoc* svDhMax = nullptr;
  SinhVienCaoDang* svCdMax = nullptr;

  int demChuaTNCaoDang = 0;
  int demChuaTNDaiHoc = 0;

  for (SinhVien* sv : ds) {
    if (SinhVienDaiHoc* dh = dynamic_cast<SinhVienDaiHoc*>(sv)) {
      // Tìm ĐTB cao nhất Đại học
      if (dh->GetDiemTB() > maxDiemTBDaiHoc) {
        maxDiemTBDaiHoc = dh->GetDiemTB();
        svDhMax = dh;
      }
      // Đếm số SV ĐH không đậu
      if (!dh->XetTotNghiep()) demChuaTNDaiHoc++;
    } else if (SinhVienCaoDang* cd = dynamic_cast<SinhVienCaoDang*>(sv)) {
      // Tìm ĐTB cao nhất Cao đẳng
      if (cd->GetDiemTB() > maxDiemTBCaoDang) {
        maxDiemTBCaoDang = cd->GetDiemTB();
        svCdMax = cd;
      }
      // Đếm số SV CĐ không đậu
      if (!cd->XetTotNghiep()) demChuaTNCaoDang++;
    }
  }

  cout << "\n===== THỐNG KÊ CHI TIẾT =====\n";

  // e. Sinh viên Đại học ĐTB cao nhất
  if (svDhMax) {
    cout << "[Cao nhất Đại học] ";
    svDhMax->Xuat();
  } else {
    cout << "Không có sinh viên Đại học.\n";
  }

  // f. Sinh viên Cao đẳng ĐTB cao nhất
  if (svCdMax) {
    cout << "[Cao nhất Cao đẳng] ";
    svCdMax->Xuat();
  } else {
    cout << "Không có sinh viên Cao đẳng.\n";
  }

  // g. Số lượng không đủ điều kiện mỗi loại
  cout << "\nSố lượng SV Cao đẳng không đủ ĐK tốt nghiệp: " << demChuaTNCaoDang;
  cout << "\nSố lượng SV Đại học không đủ ĐK tốt nghiệp: " << demChuaTNDaiHoc
       << "\n";

  // Giải phóng bộ nhớ
  for (SinhVien* sv : ds) delete sv;

  return 0;
}