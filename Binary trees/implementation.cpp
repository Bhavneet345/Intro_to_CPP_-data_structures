#include<iostream>
#include<queue>
#include "binaryTreeNode.h"

binaryTreeNode<int>* takeInput()
{
    int data, leftdata, rightdata;
    cin >> data;
    binaryTreeNode<int> *root = new binaryTreeNode<int>(data);
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << "Enter left child of " << front -> data << endl;
        cin >> leftdata;
        if(leftdata != -1)
        {
            front -> left = new binaryTreeNode<int>(leftdata);
            pending.push(front -> left);
        }
        else
        {
            front -> left = nullptr;
        }
        cout << "Enter right child of " << front -> data << endl;
        cin >> rightdata;
        if(rightdata != -1)
        {
            front -> right = new binaryTreeNode<int>(rightdata);
            pending.push(front -> right);
        }
        else
        {
            front -> right = nullptr;   
        }
    }
    return root;
}

void print(binaryTreeNode<int> *root)
{
    queue<binaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty())
    {
        binaryTreeNode<int> *front = pending.front();
        pending.pop();
        cout << front -> data << ":";
        if(front -> left != nullptr)
        {
            cout << front -> left -> data << ",";
            pending.push(front -> left);
        }
        if(front -> right != nullptr)
        {
            cout << front -> right -> data;
            pending.push(front -> right);
        }
        cout << endl;
    }
    return;
}

int main()
{
    binaryTreeNode<int> *root = takeInput();
    print(root);
    return 0;
}