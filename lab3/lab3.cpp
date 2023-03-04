#include <iostream>

#include <string>
#include <cstdint>
using namespace std;

struct LinkNode
{
    void *data;
    LinkNode *next;
};

LinkNode *head;
class Slinklist
{
private:
    int counts;
    LinkNode *start;
    LinkNode *end;

public:
    Slinklist()
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

    void insert(void *data)
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
            cout << "\nLink List Empty";
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
            cout << "\nRemove Data from Link list: " << *(int *)data;
        }
    }

    void display()
    {
        int n = 0;
        LinkNode *p = head;
        if (head == NULL)
            cout << "\nLink List Empty!";
        else
        {
            cout << "\n\nList Data : ";
            while (p != NULL)
            {

                cout << *(int *)p->data << " ";
                p = p->next;
            }

            cout << "Linked list ends here " << endl;
        }
    }

    void search(void *data)
    {
        int check = 0;
        LinkNode *p = head;
        if (p == NULL)
            cout << "\nLink List Empty";
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
                cout << "\nNode Not Found";
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
        cout << "\nNumber of Nodes: " << count;
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
            cout << "Node Data Not Found";
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

// stack adt
class Stack : Slinklist
{
public:
    void push(void *data)
    {
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

        cout << "\nPush Data into Stack: " << *(string *)stack->data;
    }

    void pop()
    {
        cout << "\nPop Data from Stack: " << *(string *)head->data << endl;
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

class Queue : Slinklist
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
        cout << "\nEnqueue Data into Queue: " << *(string *)data;
    }

    void dequeue()
    {
        if (head == NULL)
            cout << "\nQueue is Empty!";
        else
        {
            cout << "\nDequeue Data from Queue: " << *(string *)head->data;
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

int main()
{
    cout << "\n\nLinked List";

    head = NULL;
    Slinklist *list = new Slinklist();
    list->insert(new int(10));
    list->insert(new int(20));
    list->insert(new int(30));
    list->insert(new int(40));
    list->insert(new int(50));
    list->display();
    list->Remove(new int(30));
    list->display();
    list->count();
    list->search(new int(40));

    cout << "\n\nStack";
    head = NULL;
    Stack *stack = new Stack();
    stack->push(new string("A"));
    stack->push(new string("B"));
    stack->pop();
    stack->push(new string("C"));
    stack->push(new string("D"));
    stack->push(new string("E"));
    stack->peek();
    cout << "\n\nQueue";
    head = NULL;
    Queue *queue = new Queue();
    queue->enqueue(new string("QA"));
    queue->enqueue(new string("QB"));
    queue->dequeue();
    queue->enqueue(new string("QC"));
    queue->enqueue(new string("QD"));
    queue->enqueue(new string("QE"));
    queue->peekRear();
    queue->peekFront();

}
