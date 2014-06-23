/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Find sum of two numbers represented by Linked List and return the sum in same format
// Complexity : O(N+M) where N and M are the number of digits in two numbers
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

Node* CreateLinkedListFromNum(int iNum)
{
    int i;
    Node* pHead;
    pHead = new Node(iNum%10);
    iNum = iNum/10;

    while(iNum > 0)
    {
        AddNodeToList(pHead, iNum%10);

        if(iNum < 10)
        {
            break;
        }

        iNum = iNum/10;
    }

    return pHead;
}

void PrintLinkedList(Node* pHead)
{
    while(pHead->next != NULL)
    {
        cout<<pHead->iData<<" -> ";
        pHead = pHead->next;
    }
    cout<<pHead->iData<<"\n";
}

/* Adds contents of two linked lists and return the head node of resultant list */
Node* FindSum(Node* pNum1, Node* pNum2)
{		
    Node* res = NULL; // res is head node of the resultant list
    Node *temp, *prev = NULL;
    int carry = 0, sum;
 
    while (pNum1 != NULL || pNum2 != NULL) //while both lists exist
    {
        // Calculate value of next digit in resultant list. 
        // The next digit is sum of following things
        // (i)  Carry
        // (ii) Next digit of first list (if there is a next digit)
        // (ii) Next digit of second list (if there is a next digit)
        sum = carry + (pNum1? pNum1->iData: 0) + (pNum2? pNum2->iData: 0);
 
        // update carry for next calulation
        carry = (sum >= 10)? 1 : 0;
 
        // update sum if it is greater than 10
        sum = sum % 10;
 
        // Create a new node with sum as data
        temp = new Node(sum);
 
        // if this is the first node then set it as head of the resultant list
        if(res == NULL)
            res = temp;
        else // If this is not the first node then connect it to the rest.
            prev->next = temp;
 
        // Set prev for next insertion
        prev  = temp;
 
        // Move first and second pointers to next nodes
        if (pNum1) pNum1 = pNum1->next;
        if (pNum2) pNum2 = pNum2->next;
    }
 
    if (carry > 0)
      temp->next = new Node(carry);
 
    // return head of the resultant list
    return res;
}

/*void FindSum(Node* pHeadSum, Node* pHead1, Node* pHead2, int iPreCarry)
{
    int iCarry, iSum;
    iSum = 0;

    if(pHead1 == NULL && pHead2 == NULL && iPreCarry == 0)
    {
        return;
    }

    if(pHead1 != NULL)
        iSum += pHead1->iData;

    if(pHead2 != NULL)
        iSum += pHead2->iData;
    
    iSum += iPreCarry;

    iCarry = iSum/10;
    iSum = iSum%10;

    pHeadSum = new Node(iSum);
    
    cout<<"\n >>>>>> TARUN "<<iSum<<" , "<<iCarry<<" >>>>\n";
    
    if(pHead1 == NULL && pHead2 == NULL)
        FindSum(pHeadSum->next, NULL, NULL, iCarry);
    if(pHead1 != NULL && pHead2 == NULL)
        FindSum(pHeadSum->next, pHead1->next, NULL, iCarry);
    if(pHead1 == NULL && pHead2 != NULL)
        FindSum(pHeadSum->next, NULL, pHead2->next, iCarry);
    else
        FindSum(pHeadSum->next, pHead1->next, pHead2->next, iCarry);
}*/

int main()
{
    int iNum1, iNum2;
    
    cout<<"\n Enter #1 : ";
    cin>>iNum1;
    cout<<"\n Enter #2 : ";
    cin>>iNum2;

    Node* pHead1;
    Node* pHead2;

    pHead1 = CreateLinkedListFromNum(iNum1);
    pHead2 = CreateLinkedListFromNum(iNum2);

    cout<<"\n Number 1 : ";
    PrintLinkedList(pHead1);
    cout<<"\n Number 2 : ";
    PrintLinkedList(pHead2);

    Node* pHeadSum;
    pHeadSum = FindSum(pHead1, pHead2);
    cout<<"\n Sum : ";
    PrintLinkedList(pHeadSum);
    
    return 0;
}