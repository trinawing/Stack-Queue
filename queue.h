//Trina Wing
#include "calc.h"
#include <cstring>
#include <cctype>

using namespace std;

struct que_node
{
	double num;
	char opp;
	que_node * next;
};

class queue
{
	public:
	
	queue(void);
	~queue(void);
	// function to add to the list
	int enqueue(double & num, char & opp);
	//function to remove from the list
	int dequeue(void);
	//function to remove everything in the list
	int dequeue_all(void);
	//function to display the history
	int display_all(void);
	
	private:
		
		que_node * rear;


};
