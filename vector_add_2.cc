// Exercise 3
// Modify the vector addition from last time to use
// an omp for directive.
//
// Compile using 
// $$ g++ -O3 -fopenmp vector_add_2.cc -o vector_add_2
#include <omp.h>
#include <cstdio>
#include <vector>

int main(int argc, char* argv[])
{
  
  long int n = 10000000;
  std::vector<double> a(n, 1.0);
  std::vector<double> b(n, 2.0);
  std::vector<double> c(n, 0.0);

  // initialize timer
  double et = omp_get_wtime();


  for (long int i = 0; i < n; ++i)
      c[i] = a[i] + b[i];

  // finalize time
  et = omp_get_wtime() - et;

  printf("c[ 0]=%3.1f\n", c[0]);
  printf("c[-1]=%3.1f\n", c[n-1]);
  printf("time = %8.4f\n", et);

  return 0;
}
