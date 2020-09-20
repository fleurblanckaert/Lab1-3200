#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits> // numeric_limits
#include <cfloat>  // for limits of a double DBL_MIN and DBL_MAX

#include "MyConsoleInput.h"
using namespace std;


// ReadDouble function definition
double ConsoleInput::ReadDouble(const double MIN, const double MAX)
{
	

	double validNumber = 0.0; // holds the user input 

	cin >> validNumber;       // try to get input

	// remove any remaining characters from the buffer.
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	
		if (cin.fail())            // if user input fails...
		{
			cin.clear(); // Reset the fail() state of the cin object.
			cin.sync();  // clear the buffer 
			// report the problem to the user.
			cerr << "* Invalid input. Please try again and enter a numeric value.\n";
			// Try again by calling the function again (recursion)
			validNumber = ReadDouble(MIN, MAX);
		}
		else if (validNumber < MIN || validNumber > MAX)// if value is outside range...
		{
			// report the problem to the user.
			cerr << " * Invalid input. Please try again and enter a value between "
				<< MIN << " and " << MAX << ".\n";
			// Try again by call the function again (recursion)
			validNumber = ReadDouble(MIN, MAX);
		}
		
	

	return validNumber; // returns a valid value to the calling function.
}

// ReadInteger function definition
int ConsoleInput::ReadInteger(const int MIN, const int MAX)
{

	double validNumber = 0.0; // holds the user input

	validNumber = ReadDouble(1.0, MAX); // Get user input as a double

	// if(abs(validNumber - (int) validNumber) > 0.00000001) // Alternative
	if (validNumber > (int)validNumber)      // If user input is not a whole number
	{
		// report the problem to the user.
		cerr << " * Invalid input. Please try again and enter a whole number.\n";
		validNumber = ReadInteger(MIN, MAX); // try again using recursion.
	}
	
	return (int)validNumber; // returns a valid value to the calling function.
}

//Data Validation for Day
int ConsoleInput::DayValidation(const int MIN_DAY, const int MAX_DAY)
{
	double validNumber = 0.0; // holds the user input

	validNumber = ReadDouble(MIN_DAY, MAX_DAY);

	return (int)validNumber;
}

//Data Validation for Month
int ConsoleInput::MonthValidation(const int MIN_MONTH, const int MAX_MONTH)
{
	double validNumber = 0.0; // holds the user input

	validNumber = ReadDouble(MIN_MONTH, MAX_MONTH);

	return (int)validNumber;
}

//Data Validation for Year
int ConsoleInput::YearValidation(const int MIN_YEAR, const int MAX_YEAR)
{
	double validNumber = 0.0; // holds the user input

	validNumber = ReadDouble(MIN_YEAR, MAX_YEAR);

	return (int)validNumber;
}