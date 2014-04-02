/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Count the number of inversions in an integer array
// Complexity : O(n log-n)
/////////////////////////////////

#include <iostream>

using namespace std;

int Merge(int iArr[], int iMin, int iMid, int iMax)
{
    int* iTempArr = new int[iMax-iMin+1];
    int i,j,iKey;
    int iNumOfInversions=0;
    i = iMin;
    j = iMid+1;
    iKey = 0;

    while( i <= iMid && j <= iMax)
    {
	    if(iArr[i] > iArr[j])
        {
	        iTempArr[iKey++] = iArr[j++];
            iNumOfInversions += (iMid - i);
        }
	    else
	        iTempArr[iKey++] = iArr[i++];
    }

    if(i <= iMid)
    {
	    while(i <= iMid)
        {
	        iTempArr[iKey++] = iArr[i++];
            iNumOfInversions += 1;
        }
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
    return iNumOfInversions;
}

int MergeSort(int iArr[], int iMin, int iMax)
{
    int iNumOfInversions=0;

    if(iMin < iMax)
    {
	int iMid = (iMin+iMax)/2;
	iNumOfInversions = MergeSort(iArr, iMin, iMid);
	iNumOfInversions += MergeSort(iArr, iMid+1, iMax);
	iNumOfInversions += Merge(iArr, iMin, iMid, iMax); 
    }
    return iNumOfInversions;
}

int main()
{
    int iArr[] = {2, -1, 5, 2, 10, -5};
    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    
    int iNumOfInversions;
    iNumOfInversions = MergeSort(iArr, 0, N-1);
    cout<<"\n Number of total inversions : "<<iNumOfInversions<<"\n"; 
    
    return 0;
}
