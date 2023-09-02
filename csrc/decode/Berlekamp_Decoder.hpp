//
// Created by zoo2 on 18-7-14.
//

#ifndef RS256_BERLEKAMP_BERLEKAMP_H
#define RS256_BERLEKAMP_BERLEKAMP_H

#include <zconf.h>
#include <vector>
#include "csrc/GF256/GF256_poly.h"
#include "csrc/decode/RS255_Key_Equation_Decoder.hpp"

class Berlekamp_Decoder : public RS255_Key_Equation_Decoder
{
public:
  Berlekamp_Decoder(int t, u_int16_t before[255]) : RS255_Key_Equation_Decoder(t, before)
  {

  }
  Berlekamp_Decoder(int t, vector<int> before) : RS255_Key_Equation_Decoder(t, before)
  {

  }
  void GetSigmaOmega() override;
  void CheinSearch() override;
};

#endif //RS256_BERLEKAMP_BERLEKAMP_H
