#include<iostream>
#include "Arr.h"
using namespace std;


struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): val(value), left(nullptr),right(nullptr){}
};

void spiral(TreeNode* root)
{
    if(root==nullptr)
        return;
    Stack<TreeNode*>stack1;
    Stack<TreeNode*>stack2;
    stack1.Push(root);
    int level=0;
    while(!stack1.IsEmpty() || !stack2.IsEmpty())
    {
        if(level%2==0)
        {
           while(!stack1.IsEmpty())
           {
               TreeNode* node=stack1.Pop();
               cout<<node->val<<" ";

               if(node->right)
               {
                   stack2.Push(node->right);
               }
               if(node->left)
               {
                   stack2.Push(node->left);
               }
           }
        }
        else
        {
            while(!stack2.IsEmpty())
           {
               TreeNode* node=stack2.Pop();
               cout<<node->val<<" ";

               if(node->left)
               {
                   stack1.Push(node->left);
               }
               if(node->right)
               {
                   stack1.Push(node->right);
               }
           }
        }
        level++;
    }

}


int main()
{
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(7);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->right->left=new TreeNode(4);
    spiral(root);
    return 0;
}
