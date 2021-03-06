////////////////i/////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Given integer X, return TRUE if array contains A & B such that A + B = X
// Complexity : O(N logN), O(1) [Time, Space] (O(N), O(N)) also possible
/////////////////////////////////

#include <iostream>
#include <map>

using namespace std;

int LeftChildIndex(int i)
{
    return 2*i+1;
}

int RightChildIndex(int i)
{
    return 2*i+2;
} 

void shiftRight(int* arr, int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
        if (arr[swapIdx] < arr[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
        if ((rightChild <= high) && (arr[swapIdx] < arr[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
            int tmp = arr[root];
            arr[root] = arr[swapIdx];
            arr[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}

void heapify(int* arr, int low, int high)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (high - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(arr, midIdx, high);
        --midIdx;
    }
    return;
}

void heapSort(int* arr, int size)
{
    /*This will put max element in the index 0*/
    heapify(arr, 0, size-1);
    int high = size - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        int tmp = arr[high];
        arr[high] = arr[0];
        arr[0] = tmp;
        --high;
        /*Ensure heap property on remaining elements*/
        shiftRight(arr, 0, high);
    }
    return;
}

/*
Method 1 : O(N logN), O(1) [Time , Space]
Sort the Array, initialize two indexes one at the start and the other at the end of the array. If the sum of the two elements are greater than the target value, decrease the 'end' index by 1, otherwise increase the 'start' index by 1. If you find the sum, return it, if the indexes cross over and you still haven't found the sum, return false.
*/
bool CheckSumElementsInArray(int iArr[], int N, int X)
{
    int iMinIndex, iMaxIndex;
    iMinIndex = 0;
    iMaxIndex = N-1;

    while(iMinIndex < iMaxIndex)
    {
        if(iArr[iMinIndex] + iArr[iMaxIndex] < X)
        {
            iMinIndex++;
        }
        else if(iArr[iMinIndex] + iArr[iMaxIndex] > X)
        {
            iMaxIndex--;
        }
        else
            return true;
    }
    return false;
}

/* 
Method 2 : O(N), O(N) [Time , Space]
O(N) time and O(N) space:-
Put all elements in Hashmap, then loop through the array once again and check if the Hashmap contains (target - element).
*/
bool CheckSumElementsInArrayFaster(int iArr[], int N, int X)
{
    map <int, int> mapElementsPresent;
    int i;

    for(i=0; i<N; i++)
    {
        mapElementsPresent[iArr[i]] = 1;
    }

    int iTempDiff;
    for(i=0; i<N; i++)
    {
        iTempDiff = X - iArr[i];
        if(mapElementsPresent.count(iTempDiff))
            return true;
    }
    return false;
}

int main()
{
    int iArr[] = {17, 9, 5, 24, 12, 3, 15, 21};
    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }

    heapSort(iArr, N);

    cout<<"\n Sorted array (for method 1) :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";

    int X;
    bool bMatchFound;
    cout<<"\n Enter the element to check for : ";
    cin>>X;

    //bMatchFound = CheckSumElementsInArray(iArr, N, X);
    bMatchFound = CheckSumElementsInArrayFaster(iArr, N, X);
    
    if(bMatchFound == true)
        cout<<"\n Array has two elements that sum to the given input!\n";
    else
        cout<<"\n No two elements in array sum to the given input!\n";
    
    return 0;
}
