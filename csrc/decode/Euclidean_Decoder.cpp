//
// Created by zoo2 on 18-9-6.
//

#include "csrc/decode/Euclidean_Decoder.hpp"

std::pair<GF256_poly, GF256_poly> Euclidean_Decoder::GetSigmaOmega(
    GF256_poly& check_sum) {
  GF256_poly Sigma_0;
  GF256_poly Sigma_1(1);
  GF256_poly Z_0(2 * get_max_correct(), 1);
  GF256_poly Z_1 = check_sum / GF256_poly(1, 1);
  GF256_poly Sigma_2;
  int count = 0;
  GF256_poly qua;
  GF256_poly res;

  while (!(Z_1.get_degree() < Sigma_1.get_degree() &&
           Sigma_1.get_degree() <= get_max_correct()) &&
         count < 2 * get_max_correct()) {
    qua = Z_0 / Z_1;
    res = Z_0 % Z_1;
    Z_0 = Z_1;
    Z_1 = res;
    Sigma_2 = Sigma_0 + qua * Sigma_1;
    Sigma_0 = Sigma_1;
    Sigma_1 = Sigma_2;
    count++;
  }
  return std::move(std::make_pair(Sigma_1, Z_1));
}

GF256_poly Euclidean_Decoder::CheinSearch(GF256_poly& sigma_poly,
                                          GF256_poly& omega_poly) {
  vector<int> loc;

  for (int i = 0; i < 255; i++) {
    if (sigma_poly.value(GF256(1, i)) == 0) loc.push_back((255 - i) % 255);
  }

  for (int i = 0; i < loc.size(); i++) {
    GF256 err_value = omega_poly.value(GF256(1, (255 - loc[i]) % 255));
    for (int j = 0; j < loc.size(); j++) {
      if (j != i) {
        err_value =
            err_value /
            (GF256(1, loc[j]) * GF256(1, (255 - loc[i]) % 255) + GF256(0, 1));
      }
    }
    GF256 a(1, loc[i]);
    GF256_poly des_poly;
    des_poly =
        des_poly + GF256_poly(loc[i], err_value) / sigma_poly.get_coef(0) / a;
  }
}
