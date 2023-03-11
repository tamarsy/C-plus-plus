#pragma once
#include "Queue.h"
#include "Stack.h"

template <class T>
class QueueStack : public Queue<T>
{
protected:
	Stack* data;
public:
	// constructor
	QueueStack();

	// empty and delete all elements from the stack
	void clear() override;

	//dequeue: remove the value from the stack
	int dequeue() override;

	//enqueue: add a value to the stuck
	void enqueue(int value) override;

	//return the first element of the queue
	int front() override;

	//test to see if the List is empty
	bool isEmpty() const override;
};




