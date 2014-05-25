/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Given a Binary Tree, check if it is balanced
// Complexity : O(N)
/////////////////////////////////

#include <iostream>

using namespace std;

class Node
{
    int iData;
public:
    Node* rightChild;
    Node* leftChild;
};

int MaxDepth(Node* pNode)
{
    if(pNode == NULL)
    {
        return 0;
    }
    
    int iDepthLeft, iDepthRight;
    
    iDepthLeft = MaxDepth(pNode->leftChild);
    iDepthRight = MaxDepth(pNode->rightChild);

    if(iDepthLeft > iDepthRight)
    {   
        return iDepthLeft+1;
    }
    else
    {
        return iDepthRight+1;
    }
}

int MinDepth(Node* pNode)
{
    if(pNode == NULL)
    {
        return 0;
    }
    
    int iDepthLeft, iDepthRight;
    
    iDepthLeft = MinDepth(pNode->leftChild);
    iDepthRight = MinDepth(pNode->rightChild);

    if(iDepthLeft < iDepthRight)
    {
        return iDepthLeft+1;
    }
    else
    {
        return iDepthRight+1;
    }
}

bool CheckTreeBalance(Node* pRoot)
{
    if( MaxDepth(pRoot) - MinDepth(pRoot) > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    Node* pRoot;
   
    //TO DO : Alocate pRoot here (root of Binary Tree)
   
    if(CheckTreeBalance(pRoot))
    {
        cout<<"\n Given binary tree is balanced!";
    }
    else
    {
        cout<<"\n Given binary tree is not balanced!";
    }
    cout<<"\n";

    return 0;
}
