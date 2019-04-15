#include "utils.h"
/*
 * Add your unoptimized implementation here
 */
double* my_solver(int N, double *A, double* B) {
	printf("OPT SOLVER\n");

  register double *res = malloc(N*N*sizeof(double));
  register double *suma = malloc(N*N*sizeof(double));

  
   for (register int i = 0; i < N; i++) {
        register int index = i * N;
    for (register int k = 0; k < N; k++) {
        register int index_ = k * N;
      for (register int j = i; j < N; j++) {
        *(suma + index + j) += *(B + index_ + j) * *(A + index_ + i) + *(A + index_ + j) * *(B + index_ + i);
      }
    }
  }
  
   for (register int i = 0; i < N; i++) {
       register int index = i * N;
    for (register int k = i; k < N; k++) {
       register int index_ = k * N;
      for (register int j = i; j < N; j++) {
        *(res + index + j) += *(suma + index + k) * *(suma + index_ + j);
      }
    }
  }

  free(suma);
        return res;
}