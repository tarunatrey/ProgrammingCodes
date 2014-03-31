////////////////i/////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Quick Sort an integer array
// Complexity : O(n log-n) [Worst case: n^2]
/////////////////////////////////

#include <iostream>

using namespace std;

void QuickSort(int iArr[], int iLeft, int iRight)
{
    // partition
    int i,j,iPivot,iTemp;
    i = iLeft;
    j = iRight;
    iPivot = iArr[(i+j)/2];
    
    while( i <= j)
    {
	while(iArr[i] < iPivot)
	    i++;
	while(iArr[j] > iPivot)
	    j--;
	if(i <= j)
	{
	    iTemp = iArr[i];
	    iArr[i] = iArr[j];
	    iArr[j] = iTemp;
	    i++;
	    j--;
	}
    }
    
    // recursion
    if(iLeft < j)
	QuickSort(iArr, iLeft, j);
    if(i < iRight)
	QuickSort(iArr, i, iRight);
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

    QuickSort(iArr, 0, N-1);

    cout<<"\n Sorted array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";
    
    return 0;
}
