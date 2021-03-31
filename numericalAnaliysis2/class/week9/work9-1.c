#include <stdio.h>
#include <math.h>

int main(void) {
  int i, n;
  double k2;
  printf("Input a number of steps (N) : ");
  scanf("%d", &n);
  FILE *fp;
  fp = fopen("work9-1.d", "w");
  
  double u = 0.;
  double t = 0.;
  double dt = 2. * M_PI / (double)n;

  for (i=0; i<=n; i++) {
    fprintf(fp, "%4d  %.16f  %.16f\n", i, t, u);
    k2 = cos(t + 0.5 * dt);
    u += dt * k2;
    t += dt;
  }

  fclose(fp);
  return 0;
}