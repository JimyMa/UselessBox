//
// Created by zoo2 on 18-7-14.
//

#ifndef RS256_BERLEKAMP_BERLEKAMP_H
#define RS256_BERLEKAMP_BERLEKAMP_H

#include <zconf.h>

#include <vector>

#include "csrc/GF256/GF256_poly.h"
#include "csrc/decode/RS255_Key_Equation_Decoder.hpp"

class Berlekamp_Decoder : public RS255_Key_Equation_Decoder {
 public:
  Berlekamp_Decoder(int t) : RS255_Key_Equation_Decoder(t) {}

  GF256_poly CheinSearch(GF256_poly& sigma, GF256_poly& omega) override;

  std::pair<GF256_poly, GF256_poly> GetSigmaOmega(
      GF256_poly& check_sum) override;
};

#endif  // RS256_BERLEKAMP_BERLEKAMP_H
