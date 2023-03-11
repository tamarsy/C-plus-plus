#pragma once
#include <iostream>
#include "QueueVector.h"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int height();
	void reflect();
	void breadthScan();

private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
};







//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}


template <class T>
int Tree<T>::height() {
	if (this->root == nullptr) { return -1; };
	if (this->root->right == nullptr &&
		this->root->left == nullptr) { return 0; };
	Tree::Node* currentRoot = this->root;
	this->root = root->left;
	T heightLeft = this->height();
	this->root = currentRoot->right;
	T heightRight = this->height();
	this->root = currentRoot;
	return (heightLeft > heightRight) ?
		heightLeft + 1 : heightRight + 1;
}


template <class T>
void Tree<T>::reflect() {
	if (!(root == nullptr)) {
		Tree::Node* temp = root->left;
		root->left = root->right;
		root->right = temp;
		Tree::Node* currentRoot = this->root;
		this->root = root->left;
		this->reflect();
		this->root = currentRoot->right;
		this->reflect();
		this->root = currentRoot;
	}
}

template <class T>
void Tree<T>::breadthScan() {
	QueueVector<Tree::Node*> myQueue(this->height());
	Tree::Node* x = this->root;
	if (x != nullptr) {
		myQueue.enqueue(x);
	}
	while (!myQueue.isEmpty()) {
		x = myQueue.dequeue();
		cout << x->value;
		if (x->left != nullptr) {
			myQueue.enqueue(x->left);
		}
		if (x->right != nullptr) {
			myQueue.enqueue(x->right);
		}
	}
}