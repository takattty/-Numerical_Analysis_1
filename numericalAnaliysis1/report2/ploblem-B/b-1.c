#include<stdio.h>
#include<math.h>

#define N 5
#define EPSILON 1.e-12
#define MAX_LOOP 50

int main(void) {
  double a[N][N+1] = {
    { 10.0, 3.0, 1.0, 2.0, 1.0, -22.0 },
    { 1.0, 19.0, 2.0, -1.0, 5.0, 27.0 },
    { -1.0, 1.0, 30.0, 1.0, 10.0, 89.0 },
    { -2.0, 0.0, 1.0, 20.0, 5.0, -73.0 },
    { -3.0, 5.0, 1.0, -2.0, 25.0, 22.0 } 
  };

  double x[N], y[N], s, q ;
  int i, j, k ;
  FILE *fp ;
  fp = fopen("b-1.d", "w");

  for( i=0; i<N; i++ ) {
    x[i] = 1.0;
  }

  printf( "Initial data\n" );
  fprintf(fp, "Initial data\n" );
  for( i=0; i<N; i++ ) {
    printf( "x%d = %9.7f  ", i, x[i]);
    fprintf(fp, "x%d = %9.7f  ", i, x[i]);

  }
  printf( "\n\n" );
  fprintf(fp, "\n\n" );


  printf( "Iteration\n");
  fprintf(fp, "Iteration\n");
  for( k=0; k<MAX_LOOP; k++ ) {
    q = 0.0 ;
    printf("%2d ", k );
    fprintf(fp, "%2d ", k);

    for( i=0; i<N; i++ ) {
      s = 0.0 ;
      for( j=0; j<N; j++ ) {
        if( i!= j ) {
          s += a[i][j] * x[j] ;
        }
      }
      y[i] = ( a[i][N] - s) / a[i][i] ;
      q += pow( (y[i] - x[i]) , 2.0);//収束判定条件
      x[i] = y[i] ;
      printf( " x%d = %9.7f ", i, x[i] );
      fprintf(fp, " x%d = %9.7f ", i, x[i] );
    }

    printf( " q = %.16e ", q);
    fprintf(fp, " q = %.16e ", q);

    printf( "\n");
    fprintf(fp, "\n");

    if( q<EPSILON ) {
      printf( "\n" );
      fprintf(fp, "\n");
      printf( "Solution\n" );
      fprintf(fp, "Solution\n" );

      for( i=0; i<N; i++ ) {
        printf( "x%d = %9.7f\n", i, x[i] );
        fprintf(fp, "x%d = %9.7f\n", i, x[i] );
      }
      return 0 ;
    }
  }

  printf( "収束せず\n" );
  fprintf(fp, "収束せず\n" );

  fclose(fp);
  return 1;
}