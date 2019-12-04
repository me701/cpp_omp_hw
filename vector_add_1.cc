// Exercise 2
// Add to arrays (here, std::vectors) in parallel using
// only the parallel directive and the thread id and count.
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

#pragma omp parallel
{
  int thread;
  int num_threads;
  long int chunk;
  long int start = 0;
  long int stop = n;

  for (long int i = start; i < stop; ++i)
      c[i] = a[i] + b[i];
} // end parallel


  // finalize time
  et = omp_get_wtime() - et;

  printf("c[ 0]=%3.1f\n", c[0]);
  printf("c[-1]=%3.1f\n", c[n-1]);
  printf("time = %8.4f\n", et);

  return 0;
}
