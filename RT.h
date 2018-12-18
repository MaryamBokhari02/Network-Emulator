#pragma once

#include"Heap.h"
#include"queue.h"
#include"Router.h"

class RT
{
	Heap Incoming_Queue; 
	Router *R; 
	queue *Outgoing_Queue; 
	int countOutgoing; 
public:
	RT(int size);
	void SendMessage(Message x); 
	void setRouter(Router a); 
	~RT();
};

