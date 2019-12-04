// Exercise 5
// Sum 1, 2, 3, ..., n in parallel.
//
// Compile using 
// $$ g++ -O3 -fopenmp sum_of_numbers.cc -o sum_of_numbers
#include <omp.h>
#include <cstdio>
#include <vector>

int main(int argc, char* argv[])
{
  
  long int n = 200000000;

  double dp = 0.0;

  // initialize timer
  double et = omp_get_wtime();

#pragma omp parallel 
{

#pragma omp for
  for (long int i = 1; i <= n; ++i)
  {
      dp += (double)i;
  }

} // end parallel

  // finalize time
  et = omp_get_wtime() - et;

  printf("       sum is =%20.1e\n", dp);
  printf("sum should be =%20.1e\n", n*(n+1)/2.0);
  printf(" elapsed time =%8.4f\n", et);

  return 0;
}
