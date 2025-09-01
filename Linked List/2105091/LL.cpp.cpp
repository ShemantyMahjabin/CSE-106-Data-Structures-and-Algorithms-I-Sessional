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


int main()
{
    int initialize,chunksize;
    cin>>initialize>>chunksize;
    linkedlist list;

    int item;
    for(int i=0;i<initialize;i++)
    {
        cin>>item;
        list.insert(item);
    }
    //list.init(initialize);
    int Q,p;
    cout<<"Which operation do you want to perform?"<<endl;
    cout<<"1.insert(item)"<<endl;
    cout<<"2.remove"<<endl;
    cout<<"3.moveToStart"<<endl;
    cout<<"4.moveToEnd"<<endl;
    cout<<"5.prev"<<endl;
    cout<<"6.next"<<endl;
    cout<<"7.length"<<endl;
    cout<<"8.currPos"<<endl;
    cout<<"9.moveToPos(int pos)"<<endl;
    cout<<"10.getValue"<<endl;
    cin>>Q;
    while(Q!=0)
    {
        switch(Q)
        {
        case 1:
        {
            cout<<"Which element do you want to insert?"<<endl;
            cin>>p;
            list.insert(p);
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 2:
        {

            int t=list.remove();
            list.displayList();
            cout<<t<<endl;
            break;
        }
        case 3:
        {
            list.moveToStart();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 4:
        {

            list.moveToEnd();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 5:
        {
            list.prev();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 6:
        {
            list.next();
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 7:
        {
            list.displayList();
            cout<<list.Length()<<endl;
            break;
        }
        case 8:
        {
            list.displayList();
            cout<<list.currPos()<<endl;
            break;
        }
        case 9:
        {
            cout<<"Input position:"<<endl;
            cin>>p;
            list.moveToPos(p);
            list.displayList();
            cout<<"-1"<<endl;
            break;
        }
        case 10:
        {
            list.displayList();
            cout<<list.getValue()<<endl;
            break;
        }
        }
        cout<<"Which operation do you want to perform?"<<endl;
        cin>>Q;

    }
    return 0;
}



