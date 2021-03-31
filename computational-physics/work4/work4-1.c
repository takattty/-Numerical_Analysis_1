#include <stdio.h>
#include <math.h>

void data_output(int ngrid, double x[], double w[][2], double f[]);

int main(void) {
  int n, j, nstep, ngrid, jn;
  double ta, tb, tau, t, xa, xb, h;
  double cc;
  double nu;
  double x[1001], w[1001][2];
  double f[1001], fini[1001];
  xa    = -1.0;
  xb    = 1.0;
  ngrid = 40;
  h     = (xb - xa)/(double)ngrid;
  ta    = 0.0;
  tb    = 0.25;
  nstep = 10;
  tau   = (tb - ta)/(double)nstep;
  cc    = 1.0;
  nu    = cc*tau/h;

  for(j=0; j<=ngrid; j++) {
    x[j] = xa + h*(double)j;
  }

  t = ta;
  for(j=0; j<=ngrid; j++) {
    if(j <= ngrid/2) { w[j][0] = 1.0; fini[j] = 1.0; }
    else             { w[j][0] = 0.0; fini[j] = 0.0; }
  }
  data_output(ngrid, x, w, fini);

  for(n=1; n<=nstep; n++) {
    t = ta + tau*(double)n;

    for(j=1; j<=ngrid-1; j++) {
      w[j][1] = w[j][0] - 0.5*nu*(w[j+1][0] - w[j-1][0]);
    }

    w[0][1] = w[1][1];

    for(j=0; j<=ngrid; j++) {
      w[j][0] = w[j][1];
    }

    for(j=0; j<=ngrid; j++) {
      jn = (int)(((x[j] - x[0]) - cc*(t - ta))/h);
      if (jn < 0){ f[j] = fini[0]; }
      else       { f[j] = fini[jn]; }
    }

    data_output(ngrid, x, w, f);
  }
}

void data_output(int ngrid, double x[], double w[][2], double f[]) {
  int j;
  for(j=0; j<=ngrid; j++) {
    printf("%15.101f %15.101f %15.101f \n", x[j], w[j][0], f[j]);
  }
  printf("\n");
}