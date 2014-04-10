/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Convert an integer array to Linked List 
// Complexity : O(N^2)
/////////////////////////////////

#include <iostream>

using namespace std;

class Node
{
 public:
    int iData;
    Node* next;
    Node(int iNum)
    {
        iData = iNum;
        next = NULL;
    }
};

void AddNodeToList(Node* pElem, int iData)
{
    while(pElem->next != NULL)
    {
        pElem = pElem->next;
    }
    Node* pTemp;
    pTemp = new Node(iData);
    pElem->next = pTemp;
}

Node* CreateLinkedListFromArray(int iArr[], int iNum)
{
    int i;
    Node* pHead;
    pHead = new Node(iArr[0]);

    for(i=1; i<iNum; i++)
    {
        AddNodeToList(pHead, iArr[i]);
    }

    return pHead;
}

void PrintLinkedList(Node* pHead)
{
    cout<<"\n Linked List : ";
    while(pHead->next != NULL)
    {
        cout<<pHead->iData<<" -> ";
        pHead = pHead->next;
    }
    cout<<pHead->iData<<"\n";
}

int main()
{
    int iArr[] = {9, -10, 8, 13, -6, 3, -1, 11, -7};

    int i, iNum;
    iNum = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(i=0; i<iNum; i++)
    {
        cout<<" "<<iArr[i];
    }

    Node* pHead;
    pHead = CreateLinkedListFromArray(iArr, iNum);
    PrintLinkedList(pHead);
    return 0;
}
