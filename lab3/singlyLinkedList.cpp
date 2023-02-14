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