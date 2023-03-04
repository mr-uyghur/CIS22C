#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "SinglyLinkedList.cpp"

class Queue : public SinglyLinkedList
{

public:
    void enqueue(void *data)
    {
        LinkNode *queue = new LinkNode();
        queue->data = data;
        queue->next = NULL;
        if (head == NULL)
            head = queue;
        else
        {
            LinkNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = queue;
        }
        cout << "\nEnqueue Data: " << *(string *)data;
    }

    void dequeue()
    {
        if (head == NULL)
            cout << "\nQueue is Empty!";
        else
        {
            cout << "\nDequeue Data: " << *(string *)head->data;
            head = head->next;
        }
    }

    void peekFront()
    {
        if (head == NULL)
            cout << "\nQueue is Empty!";
        else
        {
            cout << "\nPeek Front Queue: " << *(string *)head->data;
        }
    }

    void peekRear()
    {
        if (head == NULL)
            cout << "\nQueue is Empty!";
        else
        {
            LinkNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            cout << "\nPeek Rear Queue: " << *(string *)temp->data;
        }
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
        cout << "\nQueue is Empty!";
    }
};

#endif