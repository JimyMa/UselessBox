//
// Created by zoo2 on 18-9-6.
//

#ifndef RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP
#define RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP

#endif //RS255_BERLEKAMP_DECODER_EUCLIDEAN_HPP

#include <zconf.h>
#include <vector>
#include "GF256_poly.h"
#include "RS255_Key_Equation_Decoder.hpp"
class Euclidean_Decoder : public RS255_Key_Equation_Decoder
{
public:
  Euclidean_Decoder(int t, u_int16_t before[255]) : RS255_Key_Equation_Decoder(t, before)
  {

  }
  void GetSigmaOmega() override;
  void CheinSearch() override;
};

void EuclideanDecoder(unsigned int, u_int16_t [255], u_int16_t [255]);
