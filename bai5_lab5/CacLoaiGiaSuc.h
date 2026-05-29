#pragma once
#include "GiaSuc.h"

class Bo : public GiaSuc {
 public:
  void Keu() const override;
  int SinhCon() override;
  int ChoSua() override;
};

class Cuu : public GiaSuc {
 public:
  void Keu() const override;
  int SinhCon() override;
  int ChoSua() override;
};

class De : public GiaSuc {
 public:
  void Keu() const override;
  int SinhCon() override;
  int ChoSua() override;
};