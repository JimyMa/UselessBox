//
// Created by zoo2 on 18-7-11.
//

#ifndef RS256_GF256_HPP
#define RS256_GF256_HPP

#include <zconf.h>
#include "GF256_num_list.h"
#include <iostream>
using namespace std;

u_int16_t left_shift(u_int16_t num);
u_int16_t left_shift(u_int16_t num, unsigned int times);

class GF256 {
public:
  void check(u_int16_t num)
  {
    if (num >= 256)
      cout << "assign number must be less than or equal to 255" << endl;
  }

  void check_map() const
  {
    if(vector_rep != alpha_power[power_rep]
       || power_rep != alpha_vector[vector_rep])
    {
      cout << "mapping error" << endl;
    }
  }

  GF256()
  {
    vector_rep = 0;
    power_rep = 255;
  }

  explicit GF256(u_int16_t num)
  {
    vector_rep = num;
    power_rep = alpha_vector[num];
  }

  GF256(int flag, u_int16_t num)
  {
    if(flag == 0) //vector construct;
    {
      vector_rep = num;
      power_rep = alpha_vector[num];
    }
    if(flag == 1)
    {
      power_rep = num;
      vector_rep = alpha_power[num];
    }
    if(flag > 1)
      cout << "error construction flag" << endl;
  }

  GF256 operator +(const GF256 & a) const;

  GF256 operator +(u_int16_t num);

  GF256 operator *(const GF256 & a) const;

  GF256 operator /(const GF256 & a) const;

  bool operator==(const GF256 & a) const;

  bool operator ==(const u_int16_t num) const;

  bool operator !=(const GF256 & a) const;

  bool operator !=(const u_int16_t num) const;

  GF256 operator ^(int time) const;

  void operator +=(const GF256 & a);
  void operator +=(const u_int16_t num);

  u_int16_t get_power();

  u_int16_t get_vector();


private:
  u_int16_t power_rep = 255;
  u_int16_t vector_rep = 0;
};


#endif //RS256_GF256_HPP
