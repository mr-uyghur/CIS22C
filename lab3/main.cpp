#include <iostream>
#include "SinglyLinkedList.cpp"
#include "Queue.cpp"
#include "Stack.cpp"


int main()
{
    cout << "\n\nLinked List Testing....";
    head = NULL;
    SinglyLinkedList *list = new SinglyLinkedList();
    list->add(new int(100));
    list->add(new int(50));
    list->add(new int(66));
    list->add(new int(500));
    list->add(new int(50));
    list->display();
    list->Remove(new int(50));
    list->display();
    list->count();
    list->search(new int(66));

    cout << "\n\nStack Testing....";
    head = NULL;
    Stack *stack = new Stack();
    stack->push(new string("krone"));
    stack->push(new string("krone"));
    stack->push(new string("krone"));
    stack->push(new string("$$$$"));
    stack->push(new string("$$$$"));
    stack->pop();

    cout << "\n\nQueue Testing....";
    head = NULL;
    Queue *queue = new Queue();
    queue->enqueue(new string("str"));
    queue->enqueue(new string("str2"));
    queue->enqueue(new string("str3"));
    queue->enqueue(new string("str4"));
    queue->enqueue(new string("str5"));
    queue->dequeue();
}