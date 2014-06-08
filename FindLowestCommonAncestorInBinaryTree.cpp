/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Search for lowest common ancestor of two elements in a Binary Tree, assuming element exists in Binary Tree
// Complexity : O(N), parsing tree once
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

Node* FindCommonAncestorInBinaryTree(Node* pHead, int iNumA, int iNumB)
{
    if(pHead == NULL)
    {
        return NULL;
    }

    if(pHead->data == iNumA || pHead->data == iNumB)
    {
        return pHead;
    }

    Node* pLeftLCA = FindCommonAncestorInBinaryTree(pHead->leftChild, iNumA, iNumB);
    Node* pRightLCA = FindCommonAncestorInBinaryTree(pHead->rightChild, iNumA, iNumB);

    if(pLeftLCA && pRightLCA)
    {
        return pHead;
    }
    else if(pLeftLCA != NULL)
    {
        return pLeftLCA; 
    }
    else
    {
        return pRightLCA;
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
    cout<<"\n";

    int iNumA, iNumB;
    cout<<"\n Enter element #1 : ";
    cin>>iNumA;
    cout<<"\n Enter element #2 : ";
    cin>>iNumB;

    Node* pAncestor;
    int iAncestor;
    pAncestor = FindCommonAncestorInBinaryTree(pHead, iNumA, iNumB);
    iAncestor = pAncestor->data;

    if(iAncestor != -1)
        cout<<"\n Common ancestor for two elements in Binary Tree : "<<iAncestor<<"\n";
    else
        cout<<"\n Invalid input!!!\n";

    return 0;
}
