/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Remove duplicates from a Linked List 
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <map>

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

Node* RemoveDuplicates(Node* pHead)
{   
    map<int, int> mapLinkedList;
    Node* pNewHead;
    Node* pTemp;

    pTemp = new Node(pHead->iData);
    pNewHead = pTemp;

    mapLinkedList[pHead->iData] = 1;
    pHead = pHead->next;

    while(pHead != NULL)
    {
        if(mapLinkedList.count(pHead->iData) == false)
        {
            mapLinkedList[pHead->iData] = 1;
            AddNodeToList(pTemp, pHead->iData);
            pTemp = pTemp->next;
        }
        pHead = pHead->next;
    }
    
    return pNewHead;
}

int main()
{
    int iArr[] = {9, -10, -6, 13, -6, 3, -1, 9, 11, -7};

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
    
    cout<<"\n Removing duplicates....\n";
    pHead = RemoveDuplicates(pHead);
    PrintLinkedList(pHead);
    
    return 0;
}
