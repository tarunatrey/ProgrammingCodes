/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Determine diameter of a Binary Tree 
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

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

///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////

int HeightOfBinaryTree(Node* pNode)
{
    if(pNode == NULL)
    {
        return 0;
    }
    else
    {
        return (1 + max(HeightOfBinaryTree(pNode->leftChild), HeightOfBinaryTree(pNode->rightChild)));
    }
}

int FindDiameterOfBinaryTree(Node* pNode)
{
    if(pNode == NULL)
    {
        return 0;
    }
    else
    {
        int iRootDiameter = 1 + HeightOfBinaryTree(pNode->leftChild) + HeightOfBinaryTree(pNode->rightChild);
        
        return max(iRootDiameter, max(FindDiameterOfBinaryTree(pNode->leftChild), FindDiameterOfBinaryTree(pNode->rightChild)));
    }
}

int main()
{
    int iArr[] = {-14, -10, -8, -6, 3, 5, 8, 9, 15};

    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }

    Node* pRoot;
    pRoot = ConvertArrToBST(iArr, 0, N-1);
    
    cout<<"\n In order traversal :- \n ";
    InOrderTraversal(pRoot);
    cout<<"\n Successful formation of a Binary Tree!\n";
    ///////////////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////
    
    cout<<"\n Diameter of the given binary tree : "<<FindDiameterOfBinaryTree(pRoot)<<"\n";

    return 0;
}
