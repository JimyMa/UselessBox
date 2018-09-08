//
// Created by zoo2 on 18-9-8.
//

#ifndef RS255_BERLEKAMP_DECODER_RS255_DECODER_H
#define RS255_BERLEKAMP_DECODER_RS255_DECODER_H
# include "GF256_poly.h"

class RS255_Key_Equation_Decoder {
public:

  RS255_Key_Equation_Decoder()
  {
    max_correct = 0;
    cout << "need to tell me max_correct and before code" << endl;
  }

  RS255_Key_Equation_Decoder(int t, u_int16_t before[255])
  {
    before_poly = GF256_poly(before);
    after_poly = before_poly;
    max_correct = t;
  }

  void GetCheckSum();

  virtual void CheinSearch();

  virtual void GetSigmaOmega();

  void Decode(u_int16_t*);

  int max_correct;
  GF256_poly before_poly;
  GF256_poly after_poly;
  GF256_poly check_sum;
  GF256_poly sigma_poly;
  GF256_poly omega_poly;
};


#endif //RS255_BERLEKAMP_DECODER_RS255_DECODER_H
