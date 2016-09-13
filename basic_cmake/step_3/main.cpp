// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFuncs.h"
#endif

void print_version( char *argv[])
{
  fprintf(stdout,"-----------------------\n");
  fprintf(stdout,"%s Version %d.%d\n",
          argv[0],
          Tutorial_VERSION_MAJOR,
          Tutorial_VERSION_MINOR);
  fprintf(stdout,"-----------------------\n");
}

int main (int argc, char *argv[])
{
  print_version(argv);

  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  #ifdef USE_MYMATH
    fprintf(stdout, "mysqrt\n");
    double outputValue = mysqrt(inputValue);
  #else
    fprintf(stdout, "sqrt\n");
    double outputValue = sqrt(inputValue);
  #endif

  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}
