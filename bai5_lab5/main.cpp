#include <ctime>
#include <iostream>
#include <vector>

#include "CacLoaiGiaSuc.h"

using namespace std;

int main() {
  // Khởi tạo seed cho hàm random ngẫu nhiên theo thời gian thực
  srand(time(0));

  vector<GiaSuc*> nongTrai;
  int soBo, soCuu, soDe;

  cout << "--- NHẬP SỐ LƯỢNG GIA SÚC BAN ĐẦU ---\n";
  cout << "Nhập số Bò: ";
  cin >> soBo;
  cout << "Nhập số Cừu: ";
  cin >> soCuu;
  cout << "Nhập số Dê: ";
  cin >> soDe;

  // Khởi tạo các đối tượng vào mảng chung
  for (int i = 0; i < soBo; ++i) nongTrai.push_back(new Bo());
  for (int i = 0; i < soCuu; ++i) nongTrai.push_back(new Cuu());
  for (int i = 0; i < soDe; ++i) nongTrai.push_back(new De());

  // Yêu cầu a: Mọi người đi vắng, gia súc kêu đói
  cout << "\n[a] Nông trại khi chủ đi vắng (Nghe tiếng kêu):\n";
  if (nongTrai.empty()) {
    cout << "Nông trại không có con vật nào.\n";
  } else {
    for (GiaSuc* gs : nongTrai) {
      gs->Keu();
    }
    cout << "\n";
  }

  // Yêu cầu b: Thống kê sau một lứa sinh và một lượt cho sữa
  int tongSua = 0;
  vector<GiaSuc*> luaMoi;  // Dùng để chứa gia súc non vừa sinh

  for (GiaSuc* gs : nongTrai) {
    // Cộng dồn lượng sữa
    tongSua += gs->ChoSua();

    // Xử lý sinh con
    int soCon = gs->SinhCon();
    for (int i = 0; i < soCon; ++i) {
      if (dynamic_cast<Bo*>(gs))
        luaMoi.push_back(new Bo());
      else if (dynamic_cast<Cuu*>(gs))
        luaMoi.push_back(new Cuu());
      else if (dynamic_cast<De*>(gs))
        luaMoi.push_back(new De());
    }
  }

  // Thêm số gia súc non vào nông trại
  for (GiaSuc* conNon : luaMoi) {
    nongTrai.push_back(conNon);
  }

  // Đếm lại số lượng bằng dynamic_cast
  int tongBo = 0, tongCuu = 0, tongDe = 0;
  for (GiaSuc* gs : nongTrai) {
    if (dynamic_cast<Bo*>(gs))
      tongBo++;
    else if (dynamic_cast<Cuu*>(gs))
      tongCuu++;
    else if (dynamic_cast<De*>(gs))
      tongDe++;
  }

  cout << "\n[b] THỐNG KÊ SAU 1 LỨA SINH VÀ 1 LƯỢT VẮT SỮA:\n";
  cout << "Tổng số Bò hiện tại: " << tongBo << " con\n";
  cout << "Tổng số Cừu hiện tại: " << tongCuu << " con\n";
  cout << "Tổng số Dê hiện tại: " << tongDe << " con\n";
  cout << "=> TỔNG LƯỢNG SỮA THU ĐƯỢC: " << tongSua << " lít\n";

  // Giải phóng bộ nhớ
  for (GiaSuc* gs : nongTrai) {
    delete gs;
  }

  return 0;
}