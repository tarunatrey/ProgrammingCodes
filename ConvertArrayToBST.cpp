/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Convert a sorted integer array to BST
// Complexity : O(n)
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
    cout<<"\n";
    return 0;
}
