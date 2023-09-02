//
// Created by zoo2 on 18-9-8.
//

#ifndef RS255_BERLEKAMP_DECODER_RS255_DECODER_H
#define RS255_BERLEKAMP_DECODER_RS255_DECODER_H

#include <vector>

#include "csrc/GF256/GF256_poly.h"

class RS255_Key_Equation_Decoder {
 public:
  size_t get_max_correct() { return max_correct; };

  RS255_Key_Equation_Decoder(int t) { max_correct = t; }

  GF256_poly GetCheckSum(GF256_poly& source);

  virtual GF256_poly CheinSearch(GF256_poly& sigma, GF256_poly& omega);

  virtual std::pair<GF256_poly, GF256_poly> GetSigmaOmega(
      GF256_poly& check_sum);

  std::vector<int32_t> Decode(std::vector<int32_t>);

 private:
  size_t max_correct;
};

#endif  // RS255_BERLEKAMP_DECODER_RS255_DECODER_H
