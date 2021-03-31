#include <stdio.h>
#include <math.h>

double fnc(double t, double y);

int main(void) {
  int i, n, nstep;
  double ta, tb, h;
  double t, w, y;
  double abs_error, frac_error, epsilon = 1.0e-16;
  double abs_error_bak = 1.0e+20, error_ratio;

  for(n=1; n<=8; n++) {
    h     = 1.0/pow(2.0,(double)n);
    ta    = 1.0;
    tb    = 6.0;
    nstep = (int)(0.5 + (tb - ta)/h);
    t     = ta;
    w     = 1.0;

    for(i=1; i<=nstep; i++) {
      w = w + h*fnc(t, w);
      t = ta + h*(double)i;
      y = t*(1.0 + log(t));
      abs_error = fabs(y - w);
      frac_error = 100.0*abs_error/fabs(y + epsilon);
    }

    error_ratio = abs_error/abs_error_bak;
    abs_error_bak = abs_error;
    if (n == 1) {continue;}
    printf("%3d %15.101f  %15.101f  %15.101f  %15.101f  %15.101f  %15.101f  \n", n, h, w, y, abs_error, frac_error, error_ratio);
  }
}

double fnc(double t, double y) {
  double f;
  f = 1.0 + y/t;
  return f;
}