#include <stdio.h>
#include <math.h>

#define N 5

int main(void)
{
  double a[N][N+1] = {
    { -(2.0), 1.0, 0.0, 0.0, 0.0, 1.0 },
    { 1.0, -(2.0), 1.0, 0.0, 0.0, 2.0 },
    { 0.0, 1.0, -(2.0), 1.0, 0.0, 3.0 },
    { 0.0, 0.0, 1.0, -(2.0), 1.0, 4.0 },
    { 0.0, 0.0, 0.0, 1.0, -(2.0), 5.0 }
  };

  int i, j, k, l;
  double m;
 
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

  for (i=0; i<N; i++){
    for (j=0; j<N+1; j++) {
      printf("%.12f ",a[i][j]);
    }
    printf("\n");
  }

  for (i=0; i<N; i++){
    a[i][N] /= a[i][i];
    printf("x%d = %.12f\n", i, a[i][N]);
  }
  return 0;
}
