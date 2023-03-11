#pragma once
#include "Stack.h"
#include "List.h"
class StackList : public Stack
{
public:
    // constructors
    StackList();
    StackList(const StackList& s);

    // Stack operations
    void clear() override;
    bool isEmpty() const override;
    int pop() override;
    void push(int value) override;
    int top() const override;

protected:
    // data fields
    List data;
};

