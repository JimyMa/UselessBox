//
// Created by zoo2 on 18-7-14.
//

#include "csrc/decode/Berlekamp_Decoder.hpp"

void Berlekamp_Decoder::GetSigmaOmega() {
  GF256_poly sigma(1);
  GF256_poly tau(1);
  GF256_poly omega(1);
  GF256_poly gamma;

  int D = 0;
  int B = 0;

  for(unsigned int i = 1; i <= 2 * max_correct; i++)
  {
      GF256_poly key_poly = (check_sum + 1) * sigma;
      GF256 delta = key_poly.get_coef(i);

      GF256_poly comp_sigma = GF256_poly(1, 1) * tau * delta;
      GF256_poly comp_omega = GF256_poly(1, 1) * gamma * delta;
      if(delta == 0
         || (2 * D) > i
         || (delta != 0 && (2 * D) == i && B == 0))
      {
          D = D;
          B = B;

          tau = GF256_poly(1, 1) * tau;
          gamma = GF256_poly(1, 1) * gamma;
      }

      else if(delta != 0
              && ((2 * D) < i || ((2 * D == i) && B == 1)))
      {
          D = i - D;
          B = 1 - B;
          tau = sigma / delta;
          gamma = omega / delta;

      }
      sigma = sigma + comp_sigma;
      omega = omega + comp_omega;
  }
  sigma_poly = sigma;
  omega_poly = omega;
}

void Berlekamp_Decoder::CheinSearch() {
  vector<int> loc;

  for(int i = 0; i < 255; i++)
  {
    if(sigma_poly.value(GF256(1, i)) == 0)
      loc.push_back((255 - i) % 255);
  }

  for(int i = 0; i < loc.size(); i++)
  {
    GF256 err_value = omega_poly.value(GF256(1, (255 - loc[i]) % 255));
    for(int j = 0; j < loc.size(); j++)
    {
      if(j != i)
      {
        err_value = err_value /
                    (GF256(1, loc[j]) * GF256(1, (255 - loc[i]) % 255)
                     + GF256(0, 1));
      }
    }
    after_poly = after_poly + GF256_poly(loc[i], err_value);
  }
}
