//Trina Wing
#include "queue.h"

queue::queue(void) //construtor
{
	rear = NULL;
}
queue::~queue(void) //destructor
{
	if (rear == NULL) return;
	if (rear->next == rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		while (rear->next != rear)
		{
			que_node * dummy = rear->next;
			rear->next = dummy->next;
			delete dummy;
		}
	delete rear;
	rear = NULL;
	}
}

int queue::enqueue(double & num, char & opp) //function to add to the queue
{
	que_node * add = new que_node;
	add->num = num;
	add->opp = opp;
	
	if(!rear)
	{
		rear = add;
		rear->next = rear;
	}
	else
	{
		que_node * dummy = rear->next;
		rear->next = add;
		rear = rear->next;
		rear->next = dummy;
	}
	return 1;
}


int queue::dequeue(void) //function to remove from the queue
{
	
	if (rear == NULL) 
		return 0;

	if (rear->next == rear)
	{
		delete rear;
		rear = NULL;
		return 1;
	}
	else
	{
		que_node * del = rear->next;
		rear->next = del->next;
		del->next = NULL;		
		delete del;
		return 1;
	}

}

int queue::dequeue_all(void) //function to delete the whole queue
{
	if (rear == NULL) return 0;

	if (rear->next == rear)
	{
		delete rear;
		rear = NULL;
		return 1;
	}
	else
	{
	while (rear->next != rear)
		{
		que_node * dummy = rear->next;
		rear->next = dummy->next;
		delete dummy;
		}
	delete rear;
	rear = NULL;
	return 1;
	}
}

int queue::display_all(void) //function to display everything in the queue
{	
	if (!rear)
		 return 0;
