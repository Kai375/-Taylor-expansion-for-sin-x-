# Taylor expansion for sin(x)

Made with C in linux ubuntu.

# Project description:

NOTICE: I did not use standard library functions in this project, but for audit purposes.

This is an efficient solution, meaning without calculating from the beginning the Exponentiation and factorial for each element in the column.

The function in this project uses Taylor expansion for the calculation of sin(x) with precision of 0.000001, that is, until the absolute value of 

the next member in the column decreases below 0.000001.

The main() program gets from the user a single double value and call my_sin function with this value as a parameter, afterward main()

will print the user input, the result from my_sin function and the result from sin(x) function that is defined in math.h library for audit purposes.

* The program will assume that the user input is valid.

* In order to prevent arithmetic overflow, the range is limited to [-25.0, 25.0].

* END OF READ ME.

  










