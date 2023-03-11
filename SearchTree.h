#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	bool  search(T value) 
	{
		return search(Tree<T>::root, value);
	}
	typename Tree<T>::Node* find(T val)
	{
		typename Tree<T>::Node* valueNode = this->root;
		while (valueNode != nullptr && val != valueNode->value) {
			if (val < valueNode->value) { valueNode = valueNode->left; }
			else { valueNode = valueNode->right; }
		}
		if (valueNode = nullptr) {
			throw "not exist in tree";
		}
		return valueNode;
	}
	void remove(T val);
	T successor(T val);
	void deleteDuplicates();

private:
	void add(typename Tree<T>::Node* current, T val) ;
	bool search(typename Tree<T>::Node* current, T val) ;
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
void SearchTree<T>::remove(T val) {
	typename Tree<T>::Node* valueNode,
		*successorFather = nullptr, *successor = nullptr;
}


template <class T>
T SearchTree<T>::successor(T val) {
	typename Tree<T>::Node* x = nullptr;
	try { x = this->find(val); }
	catch (const std::exception&) { throw "no successor"; }
	
	if (x == nullptr || x->right == nullptr) { return x->value; }
	x = x->right;
	while (x != nullptr && x->left != nullptr) {

	}
	throw "no successor";
}

template <class T>
void SearchTree<T>::deleteDuplicates() {
	if (this->root) {
		typename Tree<T>::Node* x = this->root, * current = nullptr;
		while (x && x->left && x->value == x->left->value) {
			this->remove(x->left->value);
		}
		current = x;
		this->root = x->left;
		this->deleteDuplicates();
		this->root = current->right;
		this->deleteDuplicates();
		this->root = current;
	}
}
