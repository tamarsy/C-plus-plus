//#include "QueueStack.h"
//#include "StackList.h"
//
//QueueStack::QueueStack(){
//	data = new StackList();
//}
//
//
//void QueueStack::clear() {
//	data->clear();
//}
//
//
//int QueueStack::dequeue() {
//	if (this->isEmpty()){
//		throw (const char*)"the queue is empty!";
//	}
//	return data->pop();
//}
//
//
//void QueueStack::enqueue(int value){
//	StackList tempStk;
//	while (!data->isEmpty()) {
//		tempStk.push(data->pop());
//	}
//	data->push(value);
//	while (!tempStk.isEmpty()) {
//		data->push(tempStk.pop());
//	}
//}
//
//
//int QueueStack::front() {
//	return data->top();
//}
//
//
//bool QueueStack::isEmpty() const{
//	return data->isEmpty();
//}
