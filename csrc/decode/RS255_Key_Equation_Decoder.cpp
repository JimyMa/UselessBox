//
// Created by zoo2 on 18-9-8.
//

#include "csrc/decode/RS255_Key_Equation_Decoder.hpp"

GF256_poly RS255_Key_Equation_Decoder::GetCheckSum(GF256_poly& source) {
  GF256_poly check_sum;
  for (unsigned int i = 1; i <= 2 * max_correct; i++) {
    check_sum = check_sum + GF256_poly(i, source.value(GF256(1, i)));
  }
  return check_sum;
}

std::pair<GF256_poly, GF256_poly> RS255_Key_Equation_Decoder::GetSigmaOmega(
    GF256_poly& check_sum) {
  cout << "Get error locator polynomial and error evaluator polynomial" << endl;
  return std::make_pair<GF256_poly, GF256_poly>(GF256_poly(), GF256_poly());
}

GF256_poly RS255_Key_Equation_Decoder::CheinSearch(GF256_poly& sigma,
                                                   GF256_poly& omega) {
  cout << "Chern Search Circuit" << endl;
  return GF256_poly();
}

std::vector<int32_t> RS255_Key_Equation_Decoder::Decode(
    std::vector<int32_t> source) {
  GF256_poly source_poly = GF256_poly(source);

  GF256_poly check_sum = GetCheckSum(source_poly);
  std::pair<GF256_poly, GF256_poly> sigma_omega = GetSigmaOmega(check_sum);
  GF256_poly des_poly = CheinSearch(sigma_omega.first, sigma_omega.second);
  des_poly += source_poly;

  std::vector<int32_t> des;
  for (int i = 0; i < 255; i++) {
    des.emplace_back(des_poly.get_coef(i).get_vector());
  }

  return des;
}
