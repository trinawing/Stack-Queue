#include "calculator.h"
#include "queue.h"
#include "stack.h"
using namespace std;

queue test;
stack test1;

calculator::calculator()
{
	number_to_add = 0;
	number_to_subtract = 0;
	number_to_multiply = 0;
	number_to_divide = 0;
	operation_1 = '\n';
}

int calculator::add(double & to_add)
{
	cout << "Please enter the number you wish to add: \n";
	cin >> number_to_add;
	cin.ignore(100, '\n');
	operation_1 = '+';
	cout << "The number you entered is: " << number_to_add
		<< " " << operation_1 << endl;
	
	test.enqueue(number_to_add, operation_1);
	test1.push(number_to_add, operation_1);
	return 1;
}

int calculator::subtract(double & to_subtract)
{
	cout << "Please enter the number you wish to subtract: \n";
	cin >> number_to_subtract;
	cin.ignore(100, '\n');
	operation_1 = '-';
	cout << "The number you entered is: " << number_to_subtract 
		<< " " << operation_1 << endl;
	test.enqueue(number_to_subtract, operation_1); 
	test1.push(number_to_subtract, operation_1);
	return 1;
}

int calculator::multiply(double to_multiply)
{
	cout << "Please enter the number you wish to multiply: \n";
	cin >> number_to_multiply;
	cin.ignore(100, '\n');
	operation_1 = '*';
	cout << "The number you entered is: " << number_to_multiply
		<< " " << operation_1 << endl;
	test.enqueue(number_to_multiply, operation_1);
	test1.push(number_to_multiply, operation_1);
	return 1;
}

int calculator::divide(double to_divide)
{
	cout << "Please enter the number you wish to divide: \n";
	cin >> number_to_divide;
	cin.ignore(100, '\n');
	operation_1 = '/';
	cout << "The number you entered is: " << number_to_divide
		<< " " << operation_1 << endl;
	test.enqueue(number_to_divide, operation_1);
	test1.push(number_to_divide, operation_1);
	return 1;
}

int calculator::calculate()
{

}

int calculator::last_operation(void)
{
	cout << "The last operation you requested was: ";
	test1.peek();
}

int calculator::undo(void)
{
	test1.pop();
	test.dequeue();
}
