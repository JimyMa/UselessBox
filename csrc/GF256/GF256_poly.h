//
// Created by zoo2 on 18-7-11.
//

#ifndef RS256_GF256_POLY_HPP
#define RS256_GF256_POLY_HPP

#include <vector>

#include "GF256.h"

class GF256_poly {
 public:
  GF256_poly() {
    for (int i = 0; i < 255; i++) {
      coef[i] = GF256(0);
    }
  }

  explicit GF256_poly(GF256 a[255]) {
    for (int i = 0; i < 255; i++) {
      coef[i] = a[i];
    }
  }

  explicit GF256_poly(const u_int16_t a[255]) {
    for (int i = 0; i < 255; i++) {
      coef[i] = GF256(a[i]);
    }
  }

  explicit GF256_poly(std::vector<int32_t> src) {
    for (int i = 0; i < 255; i++) {
      coef[i] = GF256(src[i]);
    }
  }

  explicit GF256_poly(u_int16_t num) {
    for (int i = 0; i < 255; i++) coef[i] = GF256(0);
    coef[0] = GF256(num);
  }

  GF256_poly(int pos, u_int16_t num) {
    for (int i = 0; i < 255; i++) coef[i] = GF256(0);
    coef[pos] = GF256(num);
  }

  explicit GF256_poly(GF256 gf256) {
    for (int i = 0; i < 255; i++) coef[i] = GF256(0);
    coef[0] = gf256;
  }

  GF256_poly(int pos, GF256 gf256) {
    for (int i = 0; i < 255; i++) coef[i] = GF256(0);
    coef[pos] = gf256;
  }

  GF256 value(GF256 gf256);

  // GF256 operator[](int i) const;
  GF256 get_coef(int i) const;

  size_t get_degree() const;

  bool operator==(GF256_poly a) const;

  bool operator==(GF256 gf256) const;

  bool operator==(int num) const;

  bool operator!=(GF256_poly a) const;

  bool operator!=(int num) const;

  bool operator!=(GF256 gf256) const;

  GF256_poly operator+(const GF256_poly &a) const;
  GF256_poly operator+(const GF256 &gf256) const;
  GF256_poly operator+(const u_int16_t num) const;

  GF256_poly operator-(const GF256_poly &a) const;
  GF256_poly operator-(const GF256 &gf256) const;
  GF256_poly operator-(const u_int16_t num) const;

  void operator+=(const GF256_poly &a);
  void operator-=(const GF256_poly &a);

  GF256_poly operator*(GF256 scale);

  GF256_poly operator/(GF256 scale) const;

  GF256_poly operator*(const GF256_poly &a) const;

  GF256_poly operator/(const GF256_poly &a) const;

  GF256_poly operator%(const GF256_poly &a) const;

 private:
  GF256 coef[255];
};

#endif  // RS256_GF256_POLY_HPP
