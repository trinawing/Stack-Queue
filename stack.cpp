#include "stack.h"
#include <cstring>
#include <cctype>
using namespace std;

stack::stack(void)
{
	head = NULL;
}

stack::~stack(void)
{
	pop_all();
}

int stack::push(double & num, char & oper)
{
	if (head == NULL)
	{
		head = new s_node;
		head->top_index = 0;
		head->entry = new s_entry[MAX];
		head->entry[head->top_index].number = num;
		head->entry[head->top_index].operation = oper;
		head->next = NULL;
		++head->top_index;
		return head->top_index;
	}

	if (head->top_index < MAX)
	{
		head->entry[head->top_index].number = num;
		head->entry[head->top_index].operation = oper;
		++head->top_index;
		return head->top_index;
	}
	else
	{
		s_node * add = new s_node;
		add->top_index = 0;
		add->entry = new s_entry[MAX];
		add->entry[add->top_index].number = num;
		add->entry[add->top_index].operation = oper;
		add->next = head;
		head = add;
		++head->top_index;
		return head->top_index;
	}

}

int stack::pop(void)
{
	if (!head) return 0;

	if (head->top_index > 0)
	{
		--head->top_index;
		return head->top_index;
	}

	if ((head->next == NULL)&&(head->top_index == 0))
	{
		delete [] head->entry;
		delete head;
		head = NULL;
		return 1;
	}

	if ((head->next != NULL)&&(head->top_index == 0))
	{
		s_node * temp = head->next;
		delete [] head->entry;
		delete head;
		head = temp;
		head->top_index = MAX;
		return 1;
	}

}

int stack::peek(void) const
{
	if (!head) return 0;

	if ((head->next == NULL) && (head->top_index < 1)) return 0;
	else
	{
	cout << head->entry[head->top_index - 1].number << " " << head->entry[head->top_index - 1].operation << " " << endl;
	}
	return 1;
}

int stack::display_all(void)
{
	if (display(head) == true)
	{
	cout << endl;
	return 1;
	}	
	else return 0;
}

bool stack::display(s_node * head)
{
	if (!head) return 0;

	display(head->next);

	for (int i = 0; i < head->top_index; i++)
		cout << head->entry[i].number << " " << head->entry[i].operation << " ";

	return true;

}
int stack::pop_all(void)
{
	if (!head) return 0;

	if (head->next == NULL)
	{
	delete []head->entry;
	delete head;
	head = NULL;
	return 1;
	}
	else
	{
	while (head->next)
	{
		s_node * temp = head;
		head = head->next;
		delete []temp->entry;
		delete temp;
	}
	delete []head->entry;
	delete head;
	head = NULL;
