#include <stdio.h>

#include <math.h>

/* Declaration of minimum tolerance acceptble.*/

#define TOLERANCE  0.000001

/* Declaration of method(s).*/

double my_sin(double);

/* This is the main program, it will carry out the given task.*/

int main()
{
    double x, given_result, my_result;

    printf("\nPlease insert a valid interval 'x' here:\n");

    scanf("%lf", &x);

    my_result = my_sin(x); /* Our function.*/

    printf("\nThe result for the given input is: %f\n", my_result);

    given_result = sin(x); /* This is the library function, we will use it for compersion with our function.*/
    
    printf("\nThe sin val of x is: %f \n" , given_result);

    given_result = given_result - my_result;

    if(given_result <= 0) /* Emulate abs function.*/
    {
        given_result = -given_result;
    }

    printf("\nThe diff is: %f \n", given_result);

    return 0;
}

double my_sin(double x)
{
    /* Variable declertion. NOTICE operator flag is for + _ only . Result starts with the first element in Taylor's series. */

    double result = x, power = x, factorial = 1, sigma = 1;

    /* j starts with 3 because the second element denominator is 3!.*/

    int operator_Flag = 0, j = 3, sign = 1;

    /* Because sin(x) is symmeterical in relation to x axis, as such, for each x value there is a ploar opposite value. This line of code takes advantage of this mathmatical fact.*/

    if(x < 0)
    {
        sign = -1;

        result *= sign;

        power *= sign;
    }

   while(sigma > TOLERANCE)
   {
       /* This variable calculates the numerator of the current element, at first it will calculate the second element's numerator.*/

      power *= x*x;

        /* This variable calculates the denominator of the current element, at first it will calculate the second element's denominator.*/

      factorial *= (j-1)*j;  

     /* Adds the constant increase of each element's denominator.*/

      j += 2;

     /* Calculates the value of the current element, at first it will calculate the second element.*/

      sigma =  power/factorial;

     /* This segment is reponsible for adding or subing sigma to result, according to operator_Flag.*/

      if(!operator_Flag)
      {
          result-= sigma;

          operator_Flag = 1;
      }
      else
      {
          result += sigma;

          operator_Flag = 0;
      }
   }

    result *= sign;

    return result;
}