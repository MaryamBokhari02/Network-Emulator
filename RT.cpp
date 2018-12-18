#include "RT.h"



RT::RT(int size= 1){
	//Router has not being created 
	R = NULL; 
	Outgoing_Queue = new queue[size]; 
	countOutgoing = size; 
}

void RT::SendMessage(Message x) {
	//Inserting the Message here 
	Incoming_Queue.Insert(x);
	//Check the Router for the next best
	string m=R->getnextbest(x.dest); 
	//Pass it to the Outgoing Queue 
	//for(int i=0; )
	Outgoing_Queue->pushdata(x);
}
void RT::setRouter(Router a) {
	R = &a; 
}
RT::~RT()
{
}
