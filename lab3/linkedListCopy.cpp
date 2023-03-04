


#include <iostream>
#include <conio.h>
#include <string>
#include <cstdint>
using namespace std;

typedef struct LinkNode
{
    void *data;
    LinkNode *next;
};

LinkNode *head;
class SinglyLinkedList
{
private:
    int counts;
    LinkNode *start;
    LinkNode *end;

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    // setter for LinkList class
    void set_count(int count)
    {
        this->counts = count;
    }
    void set_start(LinkNode *start)
    {
        this->start = start;
    }
    void set_end(LinkNode *end)
    {
        this->end = end;
    }

    // getters for LinkedList class
    int get_count()
    {
        return this->counts;
    }
    LinkNode *get_start()
    {
        return this->start;
    }
    LinkNode *get_end()
    {
        return this->end;
    }

    // adding data to LinkedList...
    void add(void *data)
    {
        LinkNode *node;
        node = new LinkNode();

        node->data = data;

        node->next = NULL;
        if (head == NULL)
            head = node;
        else
        {
            LinkNode *a = head;
            while (a->next != NULL)
            {
                a = a->next;
            }
            a->next = node;
        }
    }

    void Remove(void *data)
    {
        int n = 0;
        int n1 = 0;
        LinkNode *p = head;
        LinkNode *p1 = head;
        if (p == NULL)
        {
            cout << "\nList is Empty!";
        }
        else
        {
            LinkNode *prev;
            prev = NULL;
            while (p != NULL)
            {
                if (*(int *)p->data == *(int *)data)
                    break;
                prev = p;
                p = p->next;
            }
            prev->next = p->next;
            free(p);
            cout << "\nRemove " << *(int *)data;
        }
    }

    void display()
    {
        int n = 0;
        LinkNode *p = head;
        if (head == NULL)
            cout << "\nList is Empty!";
        else
        {
            cout << "\n\nList: ";
            while (p != NULL)
            {

                cout << *(int *)p->data << " ";
                p = p->next;
            }
        }
    }

    void search(void *data)
    {
        int check = 0;
        LinkNode *p = head;
        if (p == NULL)
            cout << "\nEmpty List!";
        else
        {
            while (p != NULL)
            {
                if (*(int *)p->data == *(int *)data)
                {
                    check++;
                    goto show;
                }
                p = p->next;
            }
        show:
            if (check == 0)
                cout << "\nOpps Node Not Found!";
            else
                cout << "\nNode Found: " << *(int *)p->data;
        }
    }

    void count()
    {
        LinkNode *p = head;
        int count = 0;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        cout << "\nCounted Data Nodes: " << count;
    }

    void update(void *data, void *newData)
    {
        int choice;
        int check = 0;
        LinkNode *p = head;
        while (p != NULL)
        {
            if (p->data == data)
            {
                p->data = newData;
                check++;
            }
            p = p->next;
        }

        if (check == 0)
            cout << "Opps Name Could Not Found!";
        else
        {
            cout << "\nNode data Update Complete!";
        }
    }

    bool isListEmpty()
    {
        LinkNode *temp = head;
        if (temp == NULL)
            return true;
        else
        {
            return false;
        }
    }
};

//////*** Stack ADT Class***//////////
class Stack : SinglyLinkedList
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

class Queue : SinglyLinkedList
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

// TESTING IN MAIN FUNCTION...//

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