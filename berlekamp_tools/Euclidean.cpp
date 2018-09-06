//
// Created by zoo2 on 18-9-6.
//

#include "Euclidean.hpp"

void EuclideanDecoder(unsigned int t,
                      u_int16_t before[255],
                      u_int16_t after[255])
{
  GF256_poly S;
  GF256_poly before_poly(before);
  for(unsigned int i = 0; i < 2 * t; i++)
  {
    S = S + GF256_poly(i, before_poly.value(GF256(1, i + 1)));
  }

  GF256_poly Sigma_0;
  GF256_poly Sigma_1(1);
  GF256_poly Z_0(2 * t, 1);
  GF256_poly Z_1 = S;
  GF256_poly Sigma_2 = S;
  int count = 0;
  GF256_poly qua;
  GF256_poly res;

  while(! (Z_1.get_degree() < Sigma_1.get_degree() &&
           Sigma_1.get_degree() <= t) && count < 2 * t )
  {
    qua = Z_0 / Z_1;
    res = Z_0 % Z_1;
    Z_0 = Z_1;
    Z_1 = res;
    Sigma_2 = Sigma_0 + qua * Sigma_1;
    Sigma_0 = Sigma_1;
    Sigma_1 = Sigma_2;
    count++;
  }


  vector<int> loc;

  for(int i = 0; i < 255; i++)
  {
    if(Sigma_1.value(GF256(1, i)) == 0)
      loc.push_back((255 - i) % 255);
  }

  GF256_poly after_poly = before_poly;

  for(int i = 0; i < loc.size(); i++)
  {
    GF256 err_value = Z_1.value(GF256(1, (255 - loc[i]) % 255));
    for(int j = 0; j < loc.size(); j++)
    {
      if(j != i)
      {
        err_value = err_value /
                    (GF256(1, loc[j]) * GF256(1, (255 - loc[i]) % 255)
                     + GF256(0, 1));
      }
    }
    GF256 a(1, loc[i]);
    after_poly = after_poly + GF256_poly(loc[i], err_value) / Sigma_1.get_coef(0) / a;
  }

  for (unsigned int i = 0; i < 255; i++)
  {
    after[i] = after_poly.get_coef(i).get_vector();
    //cout << after[i];
  }
}
