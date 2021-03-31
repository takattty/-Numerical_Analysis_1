#include <stdio.h>
#include <math.h>

int main(void) {
  int i;
  FILE *fp;
  fp = fopen("work13-2.d", "w");

  int n = 10.;
  double dt = 10. / (double)n;
  double vO = 50.;
  double theta_deg = 45.;
  double theta_rad = theta_deg * M_PI / 180. ;
  double vx = vO * cos(theta_rad);
  double vz = vO * sin(theta_rad);
  double x = 0.;
  double z = 0.;
  double g = 9.80665;
  double kvz = -g;

  for (i=0; i<=n; i++) {
    fprintf(fp, "%.16f %.16f\n", x, z);
    x += dt*vx;
    double kz = vz + (0.5*dt*kvz);
    z += dt*kz;
    vz += -dt*g;
  }

  fclose(fp);
  return 0;

}