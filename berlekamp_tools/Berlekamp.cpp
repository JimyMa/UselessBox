//
// Created by zoo2 on 18-7-14.
//

#include "Berlekamp.h"

void BerlekampDecoder(unsigned int t,
                      u_int16_t before[255],
                      u_int16_t after[255]) {
    GF256_poly S;
    GF256_poly before_poly(before);
    for(unsigned int i = 1; i <= 2 * t; i++)
    {
        S = S + GF256_poly(i, before_poly.value(GF256(1, i)));
    }

    GF256_poly sigma(1);
    GF256_poly tau(1);
    GF256_poly omega(1);
    GF256_poly gamma;

    int D = 0;
    int B = 0;

    for(unsigned int i = 1; i <= 2 * t; i++)
    {
        GF256_poly key_poly = (S + 1) * sigma;
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

    vector<int> loc;

    for(int i = 0; i < 255; i++)
    {
        if(sigma.value(GF256(1, i)) == 0)
            loc.push_back((255 - i) % 255);
    }

    GF256_poly after_poly = before_poly;

    for(int i = 0; i < loc.size(); i++)
    {
        GF256 err_value = omega.value(GF256(1, (255 - loc[i]) % 255));
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

    for (unsigned int i = 0; i < 255; i++)
    {
        after[i] = after_poly.get_coef(i).get_vector();
        //cout << after[i];
    }
}
