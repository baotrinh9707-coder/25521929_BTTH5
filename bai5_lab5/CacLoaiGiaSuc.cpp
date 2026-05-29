#include "CacLoaiGiaSuc.h"

using namespace std;

// --- LỚP BÒ ---
void Bo::Keu() const { cout << "Bòoooo... "; }
int Bo::SinhCon() {
  return rand() % 3 + 1;  // Sinh ngẫu nhiên từ 1 đến 3 con
}
int Bo::ChoSua() {
  return rand() % 21;  // Mức sữa từ 0 đến 20 lít
}

// --- LỚP CỪU ---
void Cuu::Keu() const { cout << "Beee... "; }
int Cuu::SinhCon() { return rand() % 3 + 1; }
int Cuu::ChoSua() {
  return rand() % 6;  // Mức sữa từ 0 đến 5 lít
}

// --- LỚP DÊ ---
void De::Keu() const { cout << "Meee... "; }
int De::SinhCon() { return rand() % 3 + 1; }
int De::ChoSua() {
  return rand() % 11;  // Mức sữa từ 0 đến 10 lít
}