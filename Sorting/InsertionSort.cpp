/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Insertion Sort an integer array
// Complexity : O(n^2)
/////////////////////////////////

#include <iostream>

using namespace std;

void InsertionSort(int iArr[], int N)
{
    int iPointer,iTemp;
    
    for(int i=1; i<N; i++)
    {
        iPointer = i;
        while(iArr[iPointer-1] > iArr[iPointer] && iPointer>0)
        {
            iTemp = iArr[iPointer];
            iArr[iPointer] = iArr[iPointer-1];
            iArr[iPointer-1] = iTemp;
	    iPointer--;
        }
    }      
}

int main()
{
    int iArr[] = {2, -5, 10, 6, 23, -18, -12, 15};
    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }

    InsertionSort(iArr, N);

    cout<<"\n Sorted array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";
    
    return 0;
}
