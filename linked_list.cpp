#include <iostream>
using namespace std;

class Link
{
public:
      Link();
      void insertNode(int val, int index);
      void print();
      void addNode(int val);
      int operator[](int index);
      int pop(int index);
      void reverse();
      ~Link();
private:
      struct Node
      {
          int value;
          Node* next;
      };

      Node* head;
      Node** tail;
};

Link::Link(): head(nullptr), tail(&head)
{}

void Link::insertNode(int val, int index)
{
    Node** curr = &head;
    for(int i = 0; i < index; i++)
        curr = &((*curr)-> next);

    Node* newNode = new Node;
    newNode-> value = val;
    newNode-> next = *curr;
    *curr = newNode;

    if(newNode->next == nullptr)
        tail = &(newNode-> next);
}

void Link::print()
{
    Node* p;
    for(p = head; p != nullptr; p = p-> next)
      cout << p-> value;
}



void Link::addNode(int val)
{
    Node* newNode = new Node;
    newNode->value = val;
    newNode->next = nullptr;

    *tail = newNode;
    tail = &(newNode->next);
}

int Link::operator[](int index)
{
    Node* p = head;
    for(int i = 0; i < index; i++)
        p = p-> next;

    return p->value;
}

int Link::pop(int index)
{
    Node** curr = &head;
    for(int i = 0; i < index; i++)
        curr = &((*curr)->next);

    Node* p = (*curr)->next;
    int temp = (*curr)->value;
    delete *curr;
    *curr = p;

    if(*curr == nullptr)
          tail = &(*curr);

    return temp;
}


void Link::reverse()
{
    Node* curr = head;
    Node* prev = nullptr;
    Node* next = curr-> next;
    while(curr != nullptr)
    {
        curr-> next = prev;
        prev = curr;
        curr = next;
        next = next-> next;
    }

    tail = &(head);
    head = curr;
}

Link::~Link()
{
    Node* curr;
    Node* p;
    for(curr = head; curr != nullptr; curr = p)
    {
        p = curr-> next;
        delete curr;
    }
}
