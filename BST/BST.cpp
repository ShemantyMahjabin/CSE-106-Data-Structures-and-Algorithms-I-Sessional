#include<iostream>
#include<fstream>
using namespace std;


class BST
{
private:
    int data;
    BST* left;
    BST* right;


public:
    BST* root;
    BST()
    {
        data=0;
        left=right=root=nullptr;
    }
    BST(int val)
    {
        data =val;
        left=right=root=nullptr;
    }





    //Insert
    BST* insertHelper(BST* root, int data)
    {
        if (root == nullptr)
        {
            return new BST(data);
        }
        if (data < root->data)
        {
            root->left = insertHelper(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = insertHelper(root->right, data);
        }
        return root;
    }



    void insert(int key)
    {
        root=insertHelper(root, key);
    }




    //delete

    BST* deleteHelper(BST* root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }


        if (key < root->data)
        {
            root->left = deleteHelper(root->left, key);

        }

        else if (key > root->data)
        {
            root->right = deleteHelper(root->right, key);

        }

        else
        {
            if (root->left == nullptr)
            {
                BST* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                BST* temp = root->left;
                delete root;
                return temp;
            }



            BST* succParent=root;
            BST* succ=root->right;
            while (succ->left != nullptr)
            {
                succParent=succ;
                succ = succ->left;
            }


            if (succParent != root)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            root->data = succ->data;
            delete succ;

        }


        return root;



    }


    void Delete(int key)
    {
        root=deleteHelper(this, key);
    }






//Find

    BST* findHelper(BST* root, int key)
    {
        if (root == nullptr || root->data == key)
        {
            return root;
        }
        if (key < root->data)
        {
            return findHelper(root->left, key);
        }
        else
        {
            return findHelper(root->right, key);
        }
    }


    bool find(int key)
    {
        return findHelper(root, key) != nullptr;
    }





//Inorder
    void Inorder(BST* root,ofstream& outfile)
    {
        if (!root)
        {
            return;
        }
        Inorder(root->left,outfile);
        outfile << root->data << " ";
        Inorder(root->right,outfile);
    }

    void Inorder(ofstream& outfile)
    {
        Inorder(root,outfile);
    }





    //preorder

    void Preorder(BST* root,ofstream& outfile)
    {
        if (root!=nullptr)
        {
            outfile << root->data << " ";
        Preorder(root->left,outfile);
        Preorder(root->right,outfile);
        }

    }

    void Preorder(ofstream& outfile)
    {

        Preorder(root,outfile);
    }




    //postorder
    void Postorder(BST* root,ofstream& outfile)
    {
        if (!root)
        {
            return;
        }

        Postorder(root->left,outfile);
        Postorder(root->right,outfile);
        outfile << root->data << " ";
    }
    void Postorder(ofstream& outfile)
    {
        Postorder(root,outfile);
    }




    //print
    void Print(BST* root,ofstream& outfile)
    {
        if(root==nullptr)
        {
            return;
        }

        outfile<<root->data;
        if(root->left || root->right)
        {
            outfile<<"(";
            Print(root->left,outfile);
            outfile<<",";
            if(root->right)
            {
                Print(root->right,outfile);
            }
            outfile<<")";

        }

    }

    void Print(ofstream& outfile)
    {
        Print(root,outfile);
    }




};

int main()
{

    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    BST b;

    char operation;
    int val;


    while(infile>>operation)
    {
        if(operation=='I')
        {
            infile>>val;
            b.insert(val);
             outfile<<"(";
            b.Print(outfile);
            outfile<<")";
            outfile<<endl;

        }

        else if(operation=='D')
        {
            infile>>val;
            b.deleteHelper(b.root,val);
            outfile<<"(";
            b.Print(outfile);
            outfile<<")";
            outfile<<endl;
        }

        else if(operation=='F')
        {
            infile >> val;
            if (b.find(val))
            {
                outfile << "found" << endl;
            }
            else
            {
                outfile << "not found" << endl;
            }
        }

        else if(operation=='T')
        {
            string TraversalType;
            infile>>TraversalType;
            if(TraversalType=="In")
            {
                b.Inorder(outfile);
                outfile<<endl;
            }
            else if(TraversalType=="Pre")
            {
                b.Preorder(outfile);
                outfile<<endl;
            }
            else if(TraversalType=="Post")
            {
                b.Postorder(outfile);
                outfile<<endl;
            }

        }
    }


    infile.close();
    outfile.close();




    return 0;
}
