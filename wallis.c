#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

 float wallis_pi(int x) 
 // x is taken in referance of count
 {
    float pi = 1;
    for (int a = 1; a < x; a++)
    {
        float num = 4.0 * a * a;
        pi *= (num / (num - 1));
    }
    return pi * 2 ;
    }
    
int main() {
  float pi;
  for (int i= 1; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}
