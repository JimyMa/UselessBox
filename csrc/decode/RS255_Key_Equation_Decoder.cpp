//
// Created by zoo2 on 18-9-8.
//

#include "csrc/decode/RS255_Key_Equation_Decoder.hpp"

void RS255_Key_Equation_Decoder::GetCheckSum() {
  for(unsigned int i = 1; i <= 2 * max_correct; i++)
  {
    check_sum = check_sum + GF256_poly(i, before_poly.value(GF256(1, i)));
  }
}

void RS255_Key_Equation_Decoder::GetSigmaOmega() {
  cout << "Get error locator polynomial and error evaluator polynomial" << endl;
}

void RS255_Key_Equation_Decoder::CheinSearch() {
  cout << "Chern Search Circuit" << endl;
}

void RS255_Key_Equation_Decoder::Decode(u_int16_t after[]) {
  GetCheckSum();
  GetSigmaOmega();
  CheinSearch();
  for(int i = 0; i < 255; i++)
  {
    after[i] = after_poly.get_coef(i).get_vector();
  }
}

void RS255_Key_Equation_Decoder::Decode(std::vector<int>& after) {
  GetCheckSum();
  GetSigmaOmega();
  CheinSearch();
  for(int i = 0; i < 255; i++)
  {
    after[i] = after_poly.get_coef(i).get_vector();
  }
}

