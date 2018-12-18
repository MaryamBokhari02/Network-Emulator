
#include "List.h"

List::List()
{
	head = NULL;
	tail = NULL;
}

void List::insertatstart(string val, string val2)
{
	{
		RoutingTable*temp = new RoutingTable;
		temp->destiination = val;
		temp->nextbest = val2;
		temp->next = head;
		head = temp;
	}
}
void List::printroutingtable()
{
	RoutingTable*currentnode = head;
	while (currentnode)
	{
		cout << "Destination  : " << currentnode->destiination << "  Next Best  : " << currentnode->nextbest << endl;
		currentnode = currentnode->next;
	}
}
string List::FindNode(string des)
{
	RoutingTable *current = head; 
	while (current != NULL)
	{
		if (current->destiination == des)
			return current->nextbest;
		current = current->next; 
	}
	return " "; 
}
RoutingTable * List::InsertNode(int pos, string val3, string val4)
{
	RoutingTable*temp = new RoutingTable;
	temp->destiination = val3;
	temp->nextbest = val4;
	temp->next = NULL;
	if (head == NULL&&tail == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	return 0;
}


List::~List()
{
}
