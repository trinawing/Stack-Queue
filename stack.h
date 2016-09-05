//Trina Wing

#include "calc.h"
#include <cstring>
#include <cctype>
using namespace std;

struct info
{
	double num;
	char opp;
};

struct stk_node
{
	int top;
	info * stk_info;
	stk_node * next;
};

const int MAX = 4;

class stack
{
	public: 
	
		stack(void);
		~stack(void);
		//function to add to the stack
		int push(double & num, char & opp);
		//function to remove the last entry from the stack
		void pop(void);
		//function to look ahead for the next opp
		void peek(void) const;
		//function to display all  
		int display_all(void);
		//Function to display the stack
		bool display(stk_node * head);
		//Function to remove everything in the stack
		int pop_all(void);
