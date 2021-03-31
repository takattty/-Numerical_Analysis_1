#include <stdio.h>
#include <math.h>

int main(void) {
  int i, n;
  double k1, k2;
  FILE *fp;
  fp = fopen("work9-2.d", "w");

  for (n=0; n<=4; n++) {
    int nn = pow(10.,n);
    double u = 1.;
    double t = 0.;
    double dt = 0.5 / (double)nn;// b - aが分子

    for (i=0; i<nn; i++) {
      k1 = u * u ;//元の式
      k2 = (u + 0.5*dt*k1) * (u + 0.5*dt*k1);
      u += dt * k2;// u = u + (dt * k2)
    }

    double error = fabs(1. - u/2.);
    fprintf(fp, "%5d %.16e\n", nn, error);
  }
  fclose(fp);
  return 0;
}