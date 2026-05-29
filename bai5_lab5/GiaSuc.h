#pragma once
#include <cstdlib>  // Cho hàm rand()
#include <iostream>

class GiaSuc {
 public:
  virtual ~GiaSuc() {}

  virtual void Keu() const = 0;
  virtual int SinhCon() = 0;
  virtual int ChoSua() = 0;
};