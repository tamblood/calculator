# calculator

A simple command line calculator written in C++.

Calculator includes its own entered string parser.

## To download

git clone https://github.com/tamblood/calculator.git

## To compile

g++ -o calculator calculator.cpp

## To run

./calculator

## Parsing Details

Accepts expression from user in the form of <integer> <operator> <integer> as a single string and calculates result e.g. "104 * 876" , "465 +  980"

There must be at least one blank between integer and operator

Accepts extra blanks in front of first integer, operator, and second integer

## Sample output

```
calculator :> ./calculator 
This program is a command line calculator.
Please enter an integer, an operator ( +, -, *, / ), and a second integer.
Example: 104 * 876 
Please enter an expression to evaluate: 23 * 8765
Result is 201595
calculator :>
```

## Sample input with spaces

```
calculator [master] :> ./calculator 
This program is a command line calculator.
Please enter an integer, an operator ( +, -, *, / ), and a second integer.
Example: 104 * 876 
Please enter an expression to evaluate:    1040   *    55786
Result is 58017440
calculator [master] :>
```

#### Limitations

Two operand limit, integer intput only

Integer division, calculator will truncate divided results to integer value

