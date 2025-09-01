#include<iostream>
using namespace std;
template<class T>
class Stack
{
    struct Node
    {
        T data;
        Node* next;
    };
    Node* top;
    int length;

public:
    Stack()
    {
        top=nullptr;
        length=0;
    }

    void clear()
    {
        top=nullptr;
    }


    void init(int l)
    {

        for(int i=0;i<l;i++)
        {
            T element;
            cin>>element;
            Push(element);

        }

    }

    void Push(T x)
    {
        Node* temp=new Node;
        temp->data=x;
        temp->next=top;
        top=temp;
        length++;
    }

    T Pop()
    {
        Node* temp=new Node;
        if(top==NULL)
        {
            return -1;
        }
        T item=top->data;
        temp=top;
        top=top->next;
        free(temp);
        length--;
        return item;
    }

    int Length()
    {
        return length;
    }
    T topValue()
    {
        return top->data;
    }
    bool isEmpty()
    {
        return top==nullptr;
    }

    void Print()
    {
        if( top== nullptr)
        {
            cout<<"< >"<<endl;
        }
        else
        {
            cout<<"< ";
            Node* temp=top;
            while(temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }

            cout<<">"<<endl;

        }
    }



void functionDeclaration()
{
    cout<<"Which task do you want to perform?"<<endl;
    cout<<"1.clear"<<endl;
    cout<<"2.push(item)"<<endl;
    cout<<"3.pop()"<<endl;
    cout<<"4.length()"<<endl;
    cout<<"5.topValue"<<endl;
    cout<<"6.isEmpty"<<endl;
    int Q;
    cin>>Q;
    while(Q!=0)
    {
        switch(Q)
        {

        case 1:
        {
            clear();
            Print();
            break;
        }
        case 2:
        {
            T p;
            cout<<"What do y want to push?"<<endl;
            cin>>p;
            Push(p);
            Print();
            break;

        }
        case 3:
        {
            if(length!=0)
            {
                cout<<Pop()<<endl;
            }
            else
            {
                cout<<"No elements to pop"<<endl;
            }
            Print();
            break;
        }
        case 4:
        {
            Print();
            cout<<Length()<<endl;
            break;
        }
        case 5:
        {
            Print();
            cout<<topValue()<<endl;
            break;
        }
        case 6:
        {
            Print();
            if(isEmpty())
            {
                cout<<"True"<<endl;
            }
            else
            {
                cout<<"False"<<endl;
            }

            break;
        }

        }
        cout<<"Which task do you want to perform?"<<endl;
        cin>>Q;

    }
}
};

int main()
{
    cout<<"What type of stack 1.int, 2.char he would like to construct?"<<endl;
    int d;
    cin>>d;
    switch(d)
    {
    case 1:
    {
        Stack<int>integerList;
        int chunk_size,length;
        cin>>chunk_size>>length;

        integerList.init(length);
        integerList.functionDeclaration();
        break;
    }
    case 2:
    {
        Stack<char>characterList;
        int chunk_size,length;
        cin>>chunk_size>>length;

        characterList.init(length);
        characterList.functionDeclaration();
        break;
    }
    }
    return 0;

}
