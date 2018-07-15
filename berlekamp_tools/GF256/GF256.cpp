//
// Created by zoo2 on 18-7-12.
//

#include "GF256.h"

GF256 GF256::operator+(const GF256 &a) const {
  //
  GF256 equal =  GF256(0, (a.vector_rep ^ this -> vector_rep));
    return equal;
}

GF256 GF256::operator+(u_int16_t num) {
  return (*this) + GF256(num);
}

GF256 GF256::operator*(const GF256 &a) const {
  if(this -> power_rep == 255 || a.power_rep == 255)
    return {0, 0};
  return {1, u_int16_t((int(a.power_rep) + int(this -> power_rep)) % 255)};
}

GF256 GF256::operator/(const GF256 &a) const {
  if(this -> power_rep == 255)
  {
    return {0, 0};
  }
  if(a.power_rep == 255)
  {
    cout << "error: divided by zero" << endl;
    return {0, 0};
  }
  int times = (int(((int)(this -> power_rep) -(int)(a.power_rep)) % 255) + 255) % 255;
  return {1, (u_int16_t)times};
}

bool GF256::operator==(const GF256 &a) const {
  this -> check_map();
  a.check_map();

  return (this -> power_rep == a.power_rep
          && this -> vector_rep == a.vector_rep);
}

bool GF256::operator==(const u_int16_t num) const {
  return this -> vector_rep == num;
}

bool GF256::operator!=(const GF256 &a) const {
  return !(*this == a);
}

bool GF256::operator!=(const u_int16_t num) const {
  return !(*this == num);
}

GF256 GF256::operator^(int time) const {
  if(*this == 0 && time == 0)
  {
    cout << "error: 0 ^ 0" << endl;
    return {0, 0};
  }

  if(*this == 0)
    return {0, 0};

  long int num = ((this -> power_rep * time) % 255 + 255) % 255;

  return {1, (u_int16_t)num};
}

void GF256::operator+=(const GF256 &a) {
  this -> vector_rep = (this -> vector_rep ^ a.vector_rep);
  this -> power_rep = alpha_vector[this -> vector_rep];

}

void GF256::operator+=(const u_int16_t num) {
  this -> vector_rep = ((this -> vector_rep) ^ num);
  this -> power_rep = alpha_vector[this -> vector_rep];
}

u_int16_t GF256::get_power() {
  return power_rep;
}

u_int16_t GF256::get_vector() {
  return vector_rep;
}
