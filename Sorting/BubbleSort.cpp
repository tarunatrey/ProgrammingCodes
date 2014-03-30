/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Bubble Sort an integer array
// Complexity : O(n^2)
/////////////////////////////////

#include <iostream>

using namespace std;

void BubbleSort(int iArr[], int N)
{
   
    int iTemp;
    
    for(int i=0; i<(N-1); i++)
    {
        for(int j=0; j<(N-i-1); j++)
        {
            if(iArr[j]>iArr[j+1])
            {
                iTemp = iArr[j];
                iArr[j] = iArr[j+1];
                iArr[j+1] = iTemp;
            }
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

    //Bubble Sort
    BubbleSort(iArr, N);

    cout<<"\n Sorted array :";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";
    
    return 0;
}
