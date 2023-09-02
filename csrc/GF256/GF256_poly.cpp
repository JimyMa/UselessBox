//
// Created by zoo2 on 18-7-12.
//

#include "GF256_poly.h"

GF256 GF256_poly::value(GF256 gf256) {
  GF256 equal;
  for(int i = 0; i < 255; i++)
  {
    equal += coef[i] * (gf256 ^ i);
  }
  return equal;
}

/*
GF256 GF256_poly::operator[](int i) const {
  return this -> coef[((i%255) + 255) % 255];
}
 */


bool GF256_poly::operator==(GF256_poly a) const {
  for(int i = 0; i < 255; i++)
  {
    if((*this).coef[i] != a.coef[i])
      return false;
  }
  return true;
}

bool GF256_poly::operator==(GF256 gf256) const {
  if((*this).coef[0] != gf256)
    return false;
  for(int i = 1; i < 255; i++)
  {
    if((*this).coef[i] != 0)
      return false;
  }
  return true;
}

bool GF256_poly::operator==(int num) const {
  if((*this).coef[0] != num)
    return false;
  for(int i = 1; i < 255; i++)
  {
    if((*this).coef[i] != 0)
      return false;
  }
  return true;
}

bool GF256_poly::operator!=(GF256_poly a) const {
  return !((*this) == a);
}

bool GF256_poly::operator!=(int num) const {
  return !(*this == num);
}

bool GF256_poly::operator!=(GF256 gf256) const {
  return !(*this == gf256);
}

GF256_poly GF256_poly::operator+(const GF256_poly &a) const {
  GF256_poly equal;
  for(int i = 0; i < 255; i++)
    equal.coef[i] = (*this).coef[i] + a.coef[i];
  return equal;
}

GF256_poly GF256_poly::operator+(const GF256 &gf256) const {
  GF256_poly equal = *this;
  equal.coef[0] = (*this).coef[0] + gf256;
  return equal;
}

GF256_poly GF256_poly::operator+(const u_int16_t num) const {
  GF256_poly equal = *this;
  equal.coef[0] = (*this).coef[0] + GF256(num);
  return equal;
}

GF256_poly GF256_poly::operator-(const GF256_poly & a) const {
  return (*this) + a;
}

GF256_poly GF256_poly::operator-(const GF256 & gf256) const {
  return (*this) + gf256;
}

GF256_poly GF256_poly::operator-(const u_int16_t num) const {
  return (*this) + num;
}

void GF256_poly::operator+=(const GF256_poly &a) {
  *this = (*this) + a;
}

void GF256_poly::operator-=(const GF256_poly &a) {
  (*this) += a;
}

GF256_poly GF256_poly::operator*(GF256 scale) {
  GF256_poly equal;
  for(int i = 0; i < 255; i++)
  {
    equal.coef[i] = (*this).coef[i] * scale;
  }
  return equal;
}

GF256_poly GF256_poly::operator/(GF256 scale) const {
  GF256_poly equal;
  for(int i = 0; i < 255; i++)
  {
    equal.coef[i] = (*this).coef[i] / scale;
  }
  return equal;
}

GF256_poly GF256_poly::operator*(const GF256_poly &a) const {
  GF256_poly equal;
  for(int i = 0; i < 255; i++)
  {
    for(int j = 0; j < 255; j++)
    {
      equal.coef[j] = equal.coef[j] +
              (*this).coef[i] * a.get_coef(j-i);
    }
  }
  return equal;
}

GF256_poly GF256_poly::operator%(const GF256_poly & a) const {
  GF256_poly res = GF256_poly(1) * (*this);

  while (res.get_degree() > a.get_degree()) {
    size_t degree_res = res.get_degree();
    size_t degree_a = a.get_degree();
    res -= a * GF256_poly(degree_res - degree_a) * (res.get_coef(degree_res) / a.get_coef(degree_a));
  }
  return res;
}

GF256_poly GF256_poly::operator/(const GF256_poly & a) const {
  GF256_poly equal = GF256_poly(GF256(0));
  GF256_poly res = (*this) * GF256_poly(1);
  while (equal.get_degree() > a.get_degree()) {
    size_t degree_res = res.get_degree();
    size_t degree_a = a.get_degree();
    GF256_poly quotient = GF256_poly(degree_res - degree_a) * (res.get_coef(degree_res) / a.get_coef(degree_a));
    res -= a * quotient;
    equal += quotient;
  }
  return equal;
}

GF256 GF256_poly::get_coef(int i) const {
  return this -> coef[((i%255) + 255) % 255];
}

size_t GF256_poly::get_degree() const {
  size_t result = 254;
  while (get_coef(result) != GF256(0) || result ==0)
    --result;
  return result;
}
