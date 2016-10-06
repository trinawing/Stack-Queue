#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#ifndef CALCULATOR
#define CALCULATOR


class calculator
{
	public:

	calculator();
	int add(double & to_add); 		//function to add a number for addition
	int subtract(double & to_subtract);	//function to add a number for subtraction
	int multiply(double to_multiply);	//function to add a number for multiplication
	int divide(double to_divide);		//function to add a number for divition
	
	int calculate();			//function to perform all requested calculation
	int last_operation(void);	        //tell the client what last calculation was
	int undo(int number);			//perform undo for number of time
	int view_history();			//view history of entry

	private:

	double number_to_add;
	double number_to_subtract;
	double number_to_multiply;
	double number_to_divide;
	double Number_to_display;
	char operation_1;

};
#endif

