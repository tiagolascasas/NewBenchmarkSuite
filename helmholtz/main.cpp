#include <cstdio>
#include "inverse_helmholtz.h"

int main()
{
    double S[121] = {100};
    double D[1331] = {200};
    double u[1331] = {300};
    double v[1331] = {400};
    double t[1331] = {500};
    double r[1331] = {600};
    double t1[1331] = {700};
    double t3[1331] = {800};
    double t0[1331] = {900};
    double t2[1331] = {1000};

    inverse_helmholtz(S, D, u, v, t, r, t1, t3, t0, t2);

    double sum_D = 0;
    double sum_u = 0;
    double sum_v = 0;
    double sum_t = 0;
    double sum_r = 0;
    double sum_t1 = 0;
    double sum_t3 = 0;
    double sum_t0 = 0;
    double sum_t2 = 0;
    for (int i = 0; i < 1331; i++) {
        sum_D += D[i];
        sum_u += u[i];
        sum_v += v[i];
        sum_t += t[i];
        sum_r += r[i];
        sum_t1 += t1[i];
        sum_t3 += t3[i];
        sum_t0 += t0[i];
        sum_t2 += t2[i];
    }
    printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", sum_D, sum_u, sum_v, sum_t, sum_r, sum_t1, sum_t3, sum_t0, sum_t2);

    return 0;
}