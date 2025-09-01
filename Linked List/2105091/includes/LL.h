#include<iostream>
using namespace std;

class linkedlist
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* curr;
    int length;
public:
    linkedlist();
    ~linkedlist();
    void init(int initialsize);
    void insert(int item);
    int remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currPos();
    void moveToPos(int pos);
    int getValue();
    void clear();
    void append(int item);
    int Search(int item);
    void displayList();
};
linkedlist::linkedlist()
{
    head=nullptr;
    tail=nullptr;
    curr=nullptr;
    length=0;
}
linkedlist::~linkedlist()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        Node* nextNode=temp->next;
        delete temp;
        temp=nextNode;
    }
}
void linkedlist:: init(int initialsize)
{
   /* for(int i=0;i<initialsize;i++)
    {
        insert(0);
    }*/
    for (int i = 0; i < initialsize; i++)
    {
        Node* newNode = new Node;
        newNode->data = i+1;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        length++;
    }

    curr = head;
}
void linkedlist::insert(int item)
{
    Node* newnode=new Node;
    newnode->data=item;
    newnode->next=NULL;
    if(length==0)
    {
        head=newnode;
        tail=newnode;
        curr=newnode;
    }
    else
    {
        newnode->next=curr->next;
        curr->next=newnode;
        if(curr==tail)
        {
            tail=newnode;
        }
    }
    length++;
    next();
}
int linkedlist::remove()
{
    if(length==0)
    {
        return -1;
    }
    int item=curr->data;

    if(curr==head)
    {
        head=curr->next;
        delete curr;
        curr=head;
    }
    else
    {
        Node* prevNode=head;
        while(prevNode->next!=curr)
        {
            prevNode=prevNode->next;
        }
        prevNode->next=curr->next;
        if(curr==tail)
        {
            tail=prevNode;
        }
        delete curr;
        curr=prevNode->next;
    }
    length--;
    return item;
}

void linkedlist::moveToStart()
{
    curr=head;
}
void linkedlist::moveToEnd()
{
    curr=tail;
}
void linkedlist::prev()
{
    if(curr!=head)
    {
        Node* temp=head;
        while(temp->next!=curr)
        {
            temp=temp->next;
        }
        curr=temp;
    }
}
void linkedlist::next()
{
    if(curr!=tail)
    {
        curr=curr->next;
    }
}
int linkedlist::Length()
{
    return length;
}
int linkedlist::currPos()
{
    Node* temp=head;
    int pos=0;
    while(temp!=curr)
    {
        temp=temp->next;
        pos++;
    }
    return pos;
}
void linkedlist::moveToPos(int pos)
{
    if(pos>=0 && pos<=length)
    {
        curr=head;
        for(int i=0;i<pos;i++)
        {
            curr=curr->next;
        }
    }
}
int linkedlist::getValue()
{
    if(curr==NULL)
    {
        return -1;
    }
    return curr->data;
}
void linkedlist::displayList()
{
    cout<<"<";
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp==curr)
        {
            cout<<"|";
        }
        cout<<temp->data<<" ";
        temp=temp->next;
    }

        cout<<">"<<endl;

}






