/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Binary search in a sorted integer array 
// Complexity : O(logN)
/////////////////////////////////

#include <iostream>

using namespace std;

bool BinarySearch(int iArr[], int N, int X)
{
    int iMin, iMid, iMax;
    iMin = 0;
    iMax = N-1;
    
    while(iMin <= iMax)
    {
        iMid = (iMin+iMax)/2;
        if(iArr[iMid] == X)
        {
            return true;
        }
        else if(iArr[iMid] > X)
        {
            iMax = iMid-1;
        }
        else if(iArr[iMid] < X)
        {
            iMin = iMid+1;
        }
    }
    return false;
}

int main()
{
    int iArr[] = {-14, -10, -8, -6, 3, 5, 8, 9, 15};

    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    
    int X;
    cout<<"\n Enter the element to search : ";
    cin>>X;
    
    if(BinarySearch(iArr, N, X) == true)
        cout<<"\n Element found in the array!\n";
    else
        cout<<"\n Element not found!!!\n";
  
    return 0;
}
