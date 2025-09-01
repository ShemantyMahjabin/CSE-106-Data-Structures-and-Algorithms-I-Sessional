#include<iostream>
using namespace std;
template <class T>
class linkedlist
{
    struct Node
    {
        T data;
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
    void insert(T item);
    T remove();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int Length();
    int currPos();
    void moveToPos(int pos);
    T getValue();
    void clear();
    void append(T item);
    int Search(T item);
    void displayList();
};
template <class T>
linkedlist<T>::linkedlist()
{
    head=nullptr;
    tail=nullptr;
    curr=nullptr;
    length=0;
}
template <class T>
linkedlist<T>::~linkedlist()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        Node* nextNode=temp->next;
        delete temp;
        temp=nextNode;
    }
}

template <class T>
void linkedlist<T>::insert(T item)
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
template <class T>
T linkedlist<T>::remove()
{
    if(length==0)
    {
        return -1;
    }
    T item=curr->data;

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
        curr=prevNode;
    }
    length--;
    return item;
}

template <class T>
void linkedlist<T>::moveToStart()
{
    curr=head;
}
template <class T>
void linkedlist<T>::moveToEnd()
{
    curr=tail;
}
template <class T>
void linkedlist<T>::prev()
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
template <class T>
void linkedlist<T>::next()
{
    if(curr!=tail)
    {
        curr=curr->next;
    }
}
template <class T>
int linkedlist<T>::Length()
{
    return length;
}
template <class T>
int linkedlist<T>::currPos()
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
template <class T>
void linkedlist<T>::moveToPos(int pos)
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
template <class T>
T linkedlist<T>::getValue()
{
    if(curr==NULL)
    {
        return -1;
    }
    return curr->data;
}
template <class T>
void linkedlist<T>::displayList()
{
    cout<<"<";
    Node* temp=head;
    while(temp!=NULL)
    {
       /* if(temp==curr)
        {
            cout<<"|";
        }*/
        cout<<temp->data<<" ";
        temp=temp->next;
    }

        cout<<">"<<endl;

}
template <class T>
void linkedlist<T>::clear()
{
    moveToStart();
    while(length>0)
    {
        remove();
        moveToStart();
    }
}







