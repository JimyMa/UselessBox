//
// Created by zoo2 on 18-9-6.
//

#ifndef RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP
#define RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP

#endif  // RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP

#include <zconf.h>

#include <vector>

#include "csrc/GF256/GF256_poly.h"
#include "csrc/decode/RS255_Key_Equation_Decoder.hpp"
class Euclidean_Decoder : public RS255_Key_Equation_Decoder {
 public:
  Euclidean_Decoder(int t) : RS255_Key_Equation_Decoder(t) {}
  std::pair<GF256_poly, GF256_poly> GetSigmaOmega(
      GF256_poly& check_sum) override;
  GF256_poly CheinSearch(GF256_poly& sigma, GF256_poly& omega) override;
};

void EuclideanDecoder(unsigned int, u_int16_t[255], u_int16_t[255]);
