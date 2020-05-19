#include <stdio.h>
#include <math.h>

#define N 4

int main(void)
{
  double a[N][N+1] = {
    { 9.0, 2.0, 1.0, 1.0, 20.0},
    { 2.0, 8.0, -2.0, 1.0, 16.0 },
    { -1.0, -2.0, 7.0, -2.0, 8.0 },
    { 1.0, -1.0, -2.0, 6.0, 17.0 }
  };

  int i, j, k, l;
  double m;
  FILE *fp ;
  fp = fopen("a-1.d", "w");
 
  for(l=0; l<N; l++) {
    for(j=0; j<N; j++) {
      m = a[j][l] / a[l][l];
      for(k=1; k<N+1; k++){
				if(j != l) {
				  a[j][k] -= m*a[l][k];
				}
      }
    }
  }

  printf("Soloution\n");
  fprintf(fp, "Soloution\n");
  for (i=0; i<N; i++){
    a[i][N] /= a[i][i];
    printf("x%d = %.12f\n", i, a[i][N]);
    fprintf(fp, "x%d = %.12f\n", i, a[i][N]);
  }

  fclose(fp);
  return 0;
}
