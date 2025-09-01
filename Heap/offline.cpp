#include<iostream>
#include<fstream>
#define MAX_SIZE 5
using namespace std;
template <class T>
class MaxPriorityQueue
{
    int maxsize;
    T *A;
    int size;
    int Left(int i)
    {
        return 2*i;
    }
    int Right(int i)
    {
        return 2*i+1;
    }
    void MaxHeapify(int index)
    {
        while(true)
        {

            int l=Left(index);

            int r=Right(index);
            int largest=index;
            if(l<=size && A[l]>A[largest])
            {
                largest=l;
            }

            if(r<=size && A[r]>A[largest])
            {
                largest=r;
            }
            if(largest!=index)
            {
                T temp=A[index];
                A[index]=A[largest];
                A[largest]=temp;
                index=largest;
            }
            else
            {
                break;
            }
        }
    }

public:
    MaxPriorityQueue()
    {

        size =0;
        maxsize=MAX_SIZE;
        A=new T[maxsize];
    }
    ~MaxPriorityQueue()
    {
        delete[] A;
    }

    int Parent(int i)
    {
        return i/2;
    }



    void Insert(T key)
    {
        size=size+1;
        if(size>=maxsize)
        {
            maxsize=maxsize*2;
            T *A2=new T[maxsize];

            for(int i=1; i<=size; i++)
            {
                A2[i]=A[i];
            }
            delete[]A;
            A=A2;
        }
        A[size]=key;
        int index=size;
        while (index > 1 && A[index] > A[index / 2])
        {
            T temp = A[index];
            A[index] = A[index / 2];
            A[index / 2] = temp;
            index /= 2;
        }

    }
    T FindMax()
    {
        return A[1];
    }
    T ExtractMax()
    {

        T max=A[1];
        A[1]=A[size];
        size=size-1;
        MaxHeapify(1);
        return max;
    }
    void IncreaseKey(int i,T key,ofstream& outfile)
    {
        if(i<1 || i>size)
        {
            outfile<<"Invalid index"<<endl;
            return;
        }
        if(key<A[i])
        {
            outfile<<"New key is not larger than the previous key"<<endl;
            return;
        }
        A[i]=key;
        while(i>1 && A[Parent(i)]<A[i])
        {
            T temp=A[i];
            A[i]=A[Parent(i)];
            A[Parent(i)]=temp;
            i=Parent(i);
        }
        outfile<<"Key increased!"<<endl;

    }
    void DecreaseKey(int i,T key,ofstream& outfile)
    {
        if(i<1 || i>size)
        {
            outfile<<"Invalid index"<<endl;
            return;
        }
        if(key>A[i])
        {
            outfile<<"New key is larger than the previous key"<<endl;
            return;
        }
        A[i]=key;
        MaxHeapify(i);
        outfile<<"Key decreased!"<<endl;
    }

    void Print(ofstream& outfile)
    {
        int levels = 0;
        int elementsInLevel = 1;
        int elementsPrinted = 0;
        outfile << "No of elements: " << size << endl;

        for (int i = 1; i <= size; ++i)
        {
            outfile << A[i] << "\t";
            ++elementsPrinted;

            if (elementsPrinted == elementsInLevel)
            {
                elementsPrinted = 0;
                elementsInLevel *= 2;
                ++levels;
                outfile << endl;
            }
        }
        outfile <<endl;

    }




    void Sort(ofstream& outfile)
    {
        int originalSize = size;
        for (int i = size; i >= 2; i--)
        {
            swap(A[1], A[i]);
            size--;
            MaxHeapify(1);
        }
        size=originalSize;
        Print(outfile);
    }


};


int main()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    MaxPriorityQueue<int> p;
    int Q,index;
    int key;

    while(infile>>Q)
    {
        switch(Q)
        {
        case 1:
        {
            infile>>key;
            p.Insert(key);
            break;
        }
        case 2:
        {
            outfile<<"Max: "<<p.FindMax()<<endl;
            break;
        }
        case 3:
        {
            outfile<<"Max: "<<p.ExtractMax()<<" has been extracted."<<endl;
            break;
        }
        case 4:
        {

            infile>>index>>key;
            p.IncreaseKey(index,key,outfile);
            break;
        }
        case 5:
        {
            infile>>index>>key;
            p.DecreaseKey(index,key,outfile);
            break;
        }
        case 6:
        {
            p.Print(outfile);
            break;
        }
        case 7:
        {
            p.Sort(outfile);
            infile.close();
            outfile.close();
            return 0;

        }
        default:
        {
            outfile << "Invalid choice. Please enter a valid option." <<endl;
            break;
        }
        }


    }

    infile.close();
    outfile.close();
    return 0;
}
