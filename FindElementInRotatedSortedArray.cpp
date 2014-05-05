/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Find an element in a rotated sorted array with distinct elements, modified Binary search
// Complexity : O(logN)
/////////////////////////////////

#include <iostream>

using namespace std;

bool BinarySearch(int iArr[], int iLeft,int iRight, int iNum)
{
    int iMin, iMid, iMax;
    iMin = iLeft;
    iMax = iRight;
    
    while(iMin <= iMax)
    {
        iMid = (iMin+iMax)/2;
        if(iArr[iMid] == iNum)
        {
            return true;
        }
        else if(iArr[iMid] > iNum)
        {
            iMax = iMid-1;
        }
        else if(iArr[iMid] < iNum)
        {
            iMin = iMid+1;
        }
    }
    return false;
}

bool FindElementInRotatedSortedArray(int iArr[], int iLeft, int iRight, int iNum)
{
    if(iLeft > iRight)
    {
        return false;
    }

    int iLeftVal, iMidVal, iRightVal;
    
    iLeftVal = iArr[iLeft];
    iRightVal = iArr[iRight];
    iMidVal = iArr[(iLeft+iRight)/2];

    if(iNum == iMidVal)
    {
        return true;
    }

    if(iLeftVal > iMidVal)
    {
        //Right array is sorted, Left is unsorted
        if(iNum > iMidVal && iNum <= iRightVal)
        {
            //Search in right half: sorted array using simple Binary search
            return BinarySearch(iArr, ((iLeft+iRight)/2 + 1), iRight, iNum);
        }
        else
        {
            //Search in left half: rotated sorted array using recursion
            return FindElementInRotatedSortedArray(iArr, iLeft, ((iLeft+iRight)/2 - 1), iNum);
        }
    }
    else if(iLeftVal < iMidVal)
    {
        //Left array is sorted, Right is unsorted
        if(iNum < iMidVal && iNum >= iLeftVal)
        {
            //Search in left half: sorted array using simple Binary search
            return BinarySearch(iArr, iLeft, ((iLeft+iRight)/2 - 1), iNum);
        }
        else
        {
            //Search in right half: rotated sorted array using recursion
            return FindElementInRotatedSortedArray(iArr, ((iLeft+iRight)/2 + 1), iRight, iNum);
        }
    }
    return false; //to avoid warning
}

int main()
{
    int iArr[] = {8, 9, 12, 14, 15, 18, 23, 2, 5, 6, 7};

    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }

    int iNum;
    cout<<"\n Enter the element to look for : ";
    cin>>iNum;

    if(FindElementInRotatedSortedArray(iArr, 0, N-1, iNum))
    {
        cout<<"\n Element found in the array!\n";
    }
    else
    {
        cout<<"\n Element not found!!!!\n";
    }
    
    return 0;
}
