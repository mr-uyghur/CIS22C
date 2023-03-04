#ifndef STACK_H
#define STACK_H



#include <iostream>
#include "SinglyLinkedList.cpp"

//////*** Stack ADT Class***//////////
class Stack : public SinglyLinkedList
{
public:
    // Stack::LIFO(last in first out)...

    void push(void *data)
    {
        // craete stack...
        LinkNode *stack = new LinkNode();
        if (head == NULL)
        {
            stack->data = data;
            stack->next = NULL;
            head = stack;
        }
        else
        {
            stack->data = data;
            stack->next = head;
            head = stack;
        }

        cout << "\nPush into Stack: " << *(string *)stack->data;
    }

    void pop()
    {
        cout << "\nPop from Stack: " << *(string *)head->data << endl;
        head = head->next;
    }

    void peek()
    {
        cout << "\nStack Peek: " << *(string *)head->data;
    }

    void Empty()
    {
        LinkNode *temp = head;
        LinkNode *next;
        while (temp != NULL)
        {
            next = temp->next;
            free(temp);
            temp = next;
        }
        cout << "\nStack is Empty!";
    }
};

#endif