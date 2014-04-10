/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Find if a Linked List has a loop, if yes return the node at the beginning of the loop
// Complexity : O(N)
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

Node* FindLoopBeginning(Node* pHead)
{
    Node* pPointer1;
    Node* pPointer2;
    
    pPointer1 = pHead;
    pPointer2 = pHead;

    while(pPointer2 != NULL)
    {
        if(pPointer2->next == NULL)
        {
            pPointer2 = pPointer2->next;
            break;
        }
        pPointer1 = pPointer1->next;
        pPointer2 = pPointer2->next->next;

        if(pPointer1 == pPointer2)
        {
            break;
        }
    }
    if(pPointer2 == NULL)
    {
        return NULL;
    }

    pPointer1 = pHead;
    
    while(pPointer1 != pPointer2)
    {
        pPointer1 = pPointer1->next;
        pPointer2 = pPointer2->next;
    }

    return pPointer1;
}

int main()
{
    int iArr[] = {9, -10, 8, 13, -6, 3, -1, 11, -7, 12};

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
   
    Node* pLoopElem; 
    pLoopElem = FindLoopBeginning(pHead);
    if(pLoopElem == NULL)
        cout<<"\n No loop exists in the given linked list!\n";
    else
        cout<<"\n Node at which loop begins : "<<pLoopElem->iData<<"\n";

    return 0;
}
