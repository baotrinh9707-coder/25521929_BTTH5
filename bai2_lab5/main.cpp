#include <iostream>
#include <vector>

#include "GiaoDichChungCu.h"
#include "GiaoDichDat.h"
#include "GiaoDichNhaPho.h"

using namespace std;

int main() {
  vector<GiaoDich*> ds;
  int chon;

  // 1. Nhập danh sách
  do {
    cout << "\n1. Thêm Đất | 2. Thêm Nhà phố | 3. Thêm Chung cư | 0. "
            "Dừng\nChọn: ";
    cin >> chon;
    GiaoDich* gd = nullptr;
    if (chon == 1)
      gd = new GiaoDichDat();
    else if (chon == 2)
      gd = new GiaoDichNhaPho();
    else if (chon == 3)
      gd = new GiaoDichChungCu();

    if (gd) {
      gd->Nhap();
      gd->TinhThanhTien();  // Tính ngay lúc nhập xong
      ds.push_back(gd);
    }
  } while (chon != 0);

  // Xử lý thống kê
  int demDat = 0, demNha = 0, demChungCu = 0;
  double tongTienCC = 0;

  double maxTienNha = -1;
  GiaoDichNhaPho* nhaMax = nullptr;

  cout << "\n===== CÁC GIAO DỊCH TRONG THÁNG 12/2024 =====\n";
  bool coGDThang12 = false;

  for (GiaoDich* gd : ds) {
    // Xuất danh sách tháng 12 năm 2024
    if (gd->GetThang() == 12 && gd->GetNam() == 2024) {
      gd->Xuat();
      coGDThang12 = true;
    }

    // Đếm số lượng và tìm kiếm bằng dynamic_cast
    if (dynamic_cast<GiaoDichDat*>(gd)) {
      demDat++;
    } else if (GiaoDichNhaPho* np = dynamic_cast<GiaoDichNhaPho*>(gd)) {
      demNha++;
      if (np->GetThanhTien() > maxTienNha) {
        maxTienNha = np->GetThanhTien();
        nhaMax = np;
      }
    } else if (GiaoDichChungCu* cc = dynamic_cast<GiaoDichChungCu*>(gd)) {
      demChungCu++;
      tongTienCC += cc->GetThanhTien();
    }
  }

  if (!coGDThang12) cout << "Không có giao dịch nào trong tháng 12/2024.\n";

  // In kết quả thống kê
  cout << "\n===== THỐNG KÊ =====\n";
  cout << "Tổng số lượng giao dịch Đất: " << demDat << "\n";
  cout << "Tổng số lượng giao dịch Nhà phố: " << demNha << "\n";
  cout << "Tổng số lượng giao dịch Chung cư: " << demChungCu << "\n";

  if (demChungCu > 0) {
    cout << "Trung bình thành tiền CC: " << (long long)(tongTienCC / demChungCu)
         << "\n";
  } else {
    cout << "Không có chung cư để tính trung bình.\n";
  }

  if (nhaMax) {
    cout << "Giao dịch Nhà phố có trị giá cao nhất:\n";
    nhaMax->Xuat();
  } else {
    cout << "Không có giao dịch Nhà phố nào.\n";
  }

  // Dọn rác
  for (GiaoDich* gd : ds) delete gd;
  return 0;
}