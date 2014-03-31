/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Merge Sort an integer array
// Complexity : O(n log-n)
/////////////////////////////////

#include <iostream>

using namespace std;

void Merge(int iArr[], int iMin, int iMid, int iMax)
{
    int* iTempArr = new int[iMax-iMin+1];
    int i,j,iKey;
    i = iMin;
    j = iMid+1;
    iKey = 0;

    while( i <= iMid && j <= iMax)
    {
	if(iArr[i] > iArr[j])
	    iTempArr[iKey++] = iArr[j++];
	else
	    iTempArr[iKey++] = iArr[i++];
    }

    if(i <= iMid)
    {
	while(i <= iMid)
	    iTempArr[iKey++] = iArr[i++];
    }
    if(j <= iMax)
    {
	while(j <= iMax)
	    iTempArr[iKey++] = iArr[j++];
    }
    for(iKey=iMin; iKey<=iMax; iKey++)
    {
	iArr[iKey] = iTempArr[iKey-iMin];
    }
    delete[] iTempArr;
    return;
}

void MergeSort(int iArr[], int iMin, int iMax)
{
    if(iArr == NULL)
	return;

    if(iMin < iMax)
    {
	int iMid = (iMin+iMax)/2;
	MergeSort(iArr, iMin, iMid);
	MergeSort(iArr, iMid+1, iMax);
	Merge(iArr, iMin, iMid, iMax); 
    }
    return;
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

    MergeSort(iArr, 0, N-1);

    cout<<"\n Sorted array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";
    
    return 0;
}
