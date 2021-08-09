// -------------------------------------------------------------------------------
// math.c - a C program that calculates Sine, Cosine, Tangent, and the Exponential
// function (e^x), then compares the results to the math.h library's equivalents
// -------------------------------------------------------------------------------

#include <getopt.h>
#include <math.h>
#include <stdio.h>
#define EPSILON 0.000000010
#define OPTIONS "sctea"

// Function that calculates sine of a double in the range -2PI to 2PI
double Sin(double x) {
  // xs will be shorthand for x*x
  double xs = x * x;

  // numerator for Horner normal form of Pade approximant:
  double num
      = x * ((xs * (52785432 - 479249 * xs) - 1640635920) * xs + 11511339840);

  // denominator for Horner normal form of Pade approximant:
  double den = ((18361 * xs + 3177720) * xs + 277920720) * xs + 11511339840;

  // compute sine of x:
  double sinx = num / den;
  return sinx;
}

// Function that calculates cosine of a double in the range -2PI to 2PI
double Cos(double x) {
  // xs will be shorthand for x*x
  double xs = x * x;

  // numerator for Horner normal form of Pade approximant:
  double num = (xs * (1075032 - 14615 * xs) - 18471600) * xs + 39251520;

  // denominator for Horner normal form of Pade approximant:
  double den = ((127 * xs + 16632) * xs + 1154160) * xs + 39251520;

  // compute cosine of x:
  double cosx = num / den;
  return cosx;
}

// Function that calculates tangent (sin/cos) of a double in the range -2PI to 2PI
double Tan(double x) {
  // xs will be shorthand for x*x
  double xs = x * x;

  // numerator for Horner normal form of Pade approximant:
  double num
      = x * (xs * (xs * (xs * (xs - 990) + 135135) - 4729725) + 34459425);

  // denominator for Horner normal form of Pade approximant:
  double den = 45 * (xs * (xs * (xs * (xs - 308) + 21021) - 360360) + 765765);

  // compute tangent of x:
  double tanx = num / den;
  return tanx;
}

// Exponential function (e^x)
double Exp(double x) {
  double num = 1.0000000000;
  double sum = num;
  for (double k = 1.0000000000; fabs(num) > EPSILON; k += 1.0000000000) {
    num = x / k * num;
    sum += num;
  }
  return sum;
}

// Helper function that prints and compares my Sin function versus the
// math.h library's sin function for the range -2PI to 2 PI
void printSin(void) {
  printf("x             Sin          Library     Difference\n-            "
         " ---  "
         "        ------- "
         "    ----------\n");
  for (double i = -2.0 * M_PI; i <= 2.0 * M_PI; i += M_PI / 16.0) {
    printf("%9f%13f%13f%13f\n", i, Sin(i), sin(i), (sin(i) - Sin(i)));
  }
}

// Helper function that prints and compares my Cos function versus the
// math.h library's cos function for the range -2PI to 2 PI
void printCos(void) {
  printf("x             Cos          Library     Difference\n-            "
         " ---  "
         "        ------- "
         "    ----------\n");
  for (double i = -2.0 * M_PI; i <= 2.0 * M_PI; i += M_PI / 16.0) {
    printf("%9f%13f%13f%13f\n", i, Cos(i), cos(i), (cos(i) - Cos(i)));
  }
}

// Helper function that prints and compares my Tan function versus the
// math.h library's tan function for the range -2PI to 2 PI
void printTan(void) {
  printf("x             Tan          Library     Difference\n-            "
         " ---  "
         "        ------- "
         "    ----------\n");
  for (double i = -(M_PI / 2.0 - 0.001); i <= M_PI / 2.0 - 0.001;
       i += M_PI / 16.0) {
    printf("%9f%13f%13f%13f\n", i, Tan(i), tan(i), (tan(i) - Tan(i)));
  }
}

// Helper function that prints and compares my Exp function versus the
// math.h library's exp function for the range -2PI to 2 PI
void printExp(void) {
  printf(
      "x             Exp             Library         Difference\n-            "

      " ---  "
      "           ------- "
      "        ----------\n");
  for (double i = 0.0000000000; i <= 10.0000000000; i += 0.1000000000) {
    printf("%-14f%-16f%-16f%-14f\n", i, Exp(i), exp(i), (exp(i) - Exp(i)));
  }
}

int main(int argc, char **argv) {
  int c = 0;
  // Make sure that the user enters arguments correctly, otherwise throw error
  if (argc != 2) {
    printf("Error: incorrect usage!\nUsage: 'math' followed by '-s', '-c', "
           "'-t', '-e', OR '-a'.\n");
    return -1;
  }

  while ((c = getopt(argc, argv, OPTIONS)) != -1) {
    switch (c) {
    case 's':
      // print the output in comparison table
      printSin();
      break;
    case 'c':
      // print the output in comparison table
      printCos();
      break;
    case 't':
      // print the output in comparison table
      printTan();
      break;
    case 'e':
      // print the output in comparison table
      printExp();
      break;
    case 'a':
      // perform all tests
      printSin();
      printCos();
      printTan();
      printExp();
      break;
    }
  }

  return 0;
}
