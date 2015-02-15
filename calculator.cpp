/* Practice Problem 6 - Writing functions
 * Tam Blood CS 110 A
 * Calculator.cpp - this program functions as a simple integer command line calculator
 * accepts expression from user in the form of <integer> <operator> <integer> as a single string
 * and calculates result e.g. "104 * 876" , "465 +  980" 
 * there must be at least one blank between integer and operator
 * - accepts extra blanks in front of first integer, operator, and second integer
 * limitation of program - since is integer division, will truncate divided results to integer value
 */

#include <iostream>
#include <cmath> // for pow function
using namespace std;

// function prototypes

// show_intro tells user what program does
void show_intro();

// get_int_length accepts string and index where integer starts,
// returns length of integer
int get_length_int(char expr[], int SIZE, int start_integer_index);

//string_to_int takes a cstring as parameter, start index to start looking for integer, length of integer, 
//returns corresponding integer
int string_to_int(char expr[], int length, int start_index);

// find_start_integer returns the index of where the next integer
// starts on or after the index start_looking
int find_start_integer(char expr[], int SIZE, int start_looking);

// perform operation in expression, return result
int perform_operation(int first_int, char operator_char, int second_int);

int main()
{
  const int SIZE = 81; // const holding maximum size of expression
  char expr[SIZE]; // holds expression entered by user
  int first_int; // holds first integer in expression
  int first_int_length; // length of first integer in expression
  int first_integer_index; // index of expr of start of first integer 
  int second_int; // holds second integer
  int second_int_length; // length of second integer
  int second_integer_index; // index of second integer start
  int start_looking = 0; // index of expr to start looking for next integer
  char operator_char;     // char holding operator ( * / + - )
  int operator_index; // holds index of location of operator within expr
  int result; // holds result of operation in expression 

  // tell user what program does 
  show_intro();

  // get string from user 
  cout << "Please enter an expression to evaluate: ";
  cin.getline(expr, 81);

  // find start index of first integer
  first_integer_index = find_start_integer(expr, SIZE, start_looking); 

  // find length of first integer in string 
  first_int_length = get_length_int(expr, SIZE, first_integer_index);

  // convert string to integer
  first_int = string_to_int(expr, first_int_length, first_integer_index);

  // find operator index, can use find_start_integer to find operator
  // start looking after the length of first integer added to index of the first integer
  operator_index = find_start_integer(expr, SIZE, first_int_length + first_integer_index);

  // add in length of first integer to find location of operator index
  operator_index += first_int_length + first_integer_index;

  // set operator_char
  operator_char = expr[operator_index];

  // find start index of second integer
  second_integer_index = find_start_integer(expr, SIZE, operator_index + 1);

  // add in the location of rest of expression previously processed
  second_integer_index += operator_index + 1;

  // find length of second integer in string 
  second_int_length = get_length_int(expr, SIZE, second_integer_index);

  // convert string to second integer
  second_int = string_to_int(expr, second_int_length, second_integer_index);

  // perform operation in expression
  result = perform_operation(first_int, operator_char, second_int);

  // print out result
  cout << "Result is " << result << "\n";
  
  return 0;
}

// perform operation in expression, return result
int perform_operation(int first_int, char operator_char, int second_int)
{
  int result = 0;

  switch (operator_char)
  {
    case '+':
      result = first_int + second_int;
      break;
    case '-':
      result = first_int - second_int;
      break;
    case '*':
      result = first_int * second_int;
      break;
    case '/':
      result = first_int / second_int;
      break;
    default:
      cout << "Invalid operator.\n";
   } // end switch
  
  return result;

} // end perform_operation 

// find_start_integer returns the index of where the next integer
// starts on or after the index start_looking
int find_start_integer(char expr[], int SIZE, int start_looking)
{
  int found_start_integer = -1;

  for ( int i = start_looking; i < SIZE; i++ )  // start looking at start_looking index 
  {
    if (expr[i] != ' ')  // if not a blank, integer found
      if ( found_start_integer == -1 ) // if found_start_integer hasn't already been set, set it
      {
        found_start_integer = i - start_looking;
        break;
      }
  } // end for loop

  return found_start_integer;

} // end find_start_integer

// get_int_length accepts string and index where integer starts,
// returns length of integer
int get_length_int(char expr[], int SIZE, int start_integer_index)
{
  int length = 0;

  // step through array starting at start_integer_index
  for(int i = start_integer_index; i < SIZE; i++)
  {
    switch (expr[i])
    {
      case '\t':     // if tab found, end of integer found
      case ' ':      // if blank found, end of integer found
      case '\0':     // if null character encountered, length of integer is i
        if ( length == 0 ) // only set length to i if this is first blank or null 
        {
          length = i - start_integer_index;
        }
        break;
    } // end switch
  }  // end for loop 

  return length;

} // end get_length_int

//string_to_int takes a cstring as parameter, start index to start looking for integer, length of integer, 
//returns corresponding integer
int string_to_int(char expr[], int length, int start_index)
{
  int total = 0; // to hold integer amount
  
  for (int i = start_index; i < length + start_index; i++) // loop through integer string
    {
      switch (expr[i])
      {
        case '1':   // add integer equivalent of expr[i] to total 
          total += 1 * pow(10, length + start_index - i - 1); // multiply int by power of 10 represented
          break;
        case '2':
          total += 2 * pow (10, length + start_index - i - 1);
          break;
        case '3':
          total += 3 * pow (10, length + start_index - i - 1);
          break;
        case '4':
          total += 4 * pow (10, length + start_index - i - 1);
          break;
        case '5':
          total += 5 * pow (10, length + start_index - i - 1);
          break;
        case '6':
          total += 6 * pow (10, length + start_index - i - 1);
          break;
        case '7':
          total += 7 * pow (10, length + start_index - i - 1);
          break;
        case '8':
          total += 8 * pow (10, length + start_index - i - 1);
          break;
        case '9':
          total += 9 * pow (10, length + start_index - i - 1);
          break;
        case '0':  // nothing to add if digit is 0
          break;
        case ' ':
          cout << "It's a blank!";
          break;
        case '\0':
          cout << "It's a null char!";
          break;
      }
    } // end for loop

  return total;
  
} // end string_to_int

// show_intro tells user what this program does
void show_intro()
{
  cout << "This program is a command line calculator.\n";
  cout << "Please enter an integer, an operator ( +, -, *, / ), and a second integer.\n";
  cout << "Example: 104 * 876 " << "\n";
  return;

} // end show_intro

