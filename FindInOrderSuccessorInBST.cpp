/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Find the inorder successor of an element in BST
// Complexity : O(log N), height of the tree
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

Node* pInput;
int iInput = 8;
// -14, -10, -8, -6, 3, 5, 8, 9, 15

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
    if(pTempNode->data == iInput)
    {
        pInput = pTempNode;
    } 
    
    pTempNode->leftChild = ConvertArrToBST(iArr, iMin, iMid-1);
    pTempNode->rightChild = ConvertArrToBST(iArr, iMid+1, iMax);
    return pTempNode;
}

Node* FindInorderSuccessorInBST(Node* pHead, Node* pInput)
{
    if(pHead == NULL)
        return NULL;

    Node* pInorderSucc = NULL;

    if(pInput->rightChild != NULL)
    {
        pInorderSucc = pInput->rightChild;
        while(pInorderSucc->leftChild != NULL)
        {
            pInorderSucc = pInorderSucc->leftChild;
        }

        return pInorderSucc;
    }

    //Start from root and search down the tree
    while(pHead != NULL)
    {
        if(pInput->data < pHead->data)
        {
            pInorderSucc = pHead;
            pHead = pHead->leftChild;
        }
        else if(pInput->data > pHead->data)
        {
            pHead = pHead->rightChild;
        }
        else
        {
            break;
        }
    }
    
    return pInorderSucc;
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

    Node* pInorderSucc;
    pInorderSucc = FindInorderSuccessorInBST(pHead, pInput);
    
    if(pInorderSucc != NULL)
    {
        cout<<"\n Inorder successor of "<<iInput<<" : "<<pInorderSucc->data<<"\n";
    }
    else
    {
        cout<<"\n No inorder successor of "<<iInput<<" present in BST!\n";
    }

    return 0;
}
