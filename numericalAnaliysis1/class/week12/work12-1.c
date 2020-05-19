#include <stdio.h>
#include <math.h>

#define N 5

int main(void)
{
  double a[N][N+1] = {
    { 1.0, 2.0, 3.0, 2.0, 1.0, 3.0 },
    { 1.0, 1.0, 1.0, 3.0, 4.0, 4.0 },
    { 2.0, 1.0, 2.0, 2.0, 3.0, 3.0 },
    { -1.0, -1.0, 2.0, 1.0, 3.0, 1.0 },
    { 1.0, 1.0, 3.0, 1.0, -1.0, 3.0 }
  };

  int i, j, k, l;
  double m;
 
  for(l=0; l<N-1; l++) {
    for(j=l+1; j<N; j++) {
      m = a[j][l] / a[l][l];
      for(k=l; k<N+1; k++){
	      a[j][k] -= m*a[l][k];
      }
    }
  }
  for(j=0; j<N; j++){
    for(k=0; k<N+1; k++){
      printf("%f ", a[j][k]);
    }
    printf("\n");
  }

  double x[N];
  for (j=N-1; j>=0; j--){
    x[j] = a[j][N];
    for (k=N-1; k>j; k--){
      x[j] -= a[j][k] * x[k];
    }
    x[j] /= a[j][j];
  }

  for (i=0; i<N; i++){
    printf("x%d = %f\n", i, x[i]);
  }
  return 0;
}
