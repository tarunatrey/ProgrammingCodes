/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Print all cousin nodes in a Binary Tree (all nodes at same distance from root)
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

class Node
{
 public:
    int data;
    Node* rightChild;
    Node* leftChild;
    Node(int iNum)
    {
        data = iNum;
        rightChild = NULL;
        leftChild = NULL;
    }
};

void InOrderTraversal(Node* pTempNode)
{
    if(pTempNode == NULL)
        return;

    InOrderTraversal(pTempNode->leftChild);
    cout<<pTempNode->data<<"  ";
    InOrderTraversal(pTempNode->rightChild);
}

// Function that converts array to BST : O(n)
Node* ConvertArrToBST(int iArr[], int iMin, int iMax)
{
    if(iMin > iMax)
        return NULL;

    int iMid;
    iMid = iMin + (iMax-iMin)/2; // same as (iMin+iMax)/2 but helps in avoiding overflow

    Node* pTempNode;
    pTempNode = new Node(iArr[iMid]);
    
    pTempNode->leftChild = ConvertArrToBST(iArr, iMin, iMid-1);
    pTempNode->rightChild = ConvertArrToBST(iArr, iMid+1, iMax);

    return pTempNode;
}

void PrintCousinNodes(Node* pRoot, int iDepth)
{
    if(pRoot == NULL)
    {
        return;
    }

    if(iDepth == 0)
    {
        cout<<" "<<pRoot->data;
        return;
    }
    else
    {
        PrintCousinNodes(pRoot->leftChild, iDepth-1);
        PrintCousinNodes(pRoot->rightChild, iDepth-1);
    }
}

int main()
{
    int iArr[] = {-14, -10, -8, -6, 3, 5, 8, 9, 15};

    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)  
    {
        cout<<" "<<iArr[i];
    }

    Node* pHead;
    pHead = ConvertArrToBST(iArr, 0, N-1);
    
    cout<<"\n In order traversal :- \n ";
    InOrderTraversal(pHead);
    cout<<"\n Successful formation of a Binary Tree!\n";
    
    int iDepth;
    cout<<"\n Enter depth at which you want to print cousin nodes : ";
    cin>>iDepth;
    cout<<"\n Cousin Nodes of "<<iDepth<<" : ";
    PrintCousinNodes(pHead, iDepth);
    cout<<"\n";

    return 0;
}
