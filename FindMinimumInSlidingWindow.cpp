/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Given an integer array, find minimum in a sliding window  
// Complexity : O(N)
/////////////////////////////////

#include <iostream>
#include <deque>

using namespace std;

void FindMinInSlidingWindow(int iArr[], int iSize, int iWinSize, int iArrOutput[], int iArrOutputSize)
{
    deque<int> dqWindow;

    for(int i=0; i<iWinSize; i++)
    {
        while( !dqWindow.empty() && iArr[i] <= iArr[dqWindow.back()] )
        {
            dqWindow.pop_back();
        }
        dqWindow.push_back(i);
    }

    for(int i=iWinSize; i<iSize; i++)
    {
        iArrOutput[i-iWinSize] = iArr[dqWindow.front()];
        
        while( !dqWindow.empty() && iArr[i] <= iArr[dqWindow.back()] )
        {
            dqWindow.pop_back();
        }
        while( !dqWindow.empty() && dqWindow.front() <= i-iWinSize )
        {
            dqWindow.pop_front();
        }
        dqWindow.push_back(i);
    }

    iArrOutput[iSize-iWinSize] = iArr[dqWindow.front()];
}

int main()
{
    int iArr[] = {2, 1, 3, 4, 6, 3, 8, 9, 10, 12, 56};

    int iSize;
    iSize = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<iSize; i++)
    {
        cout<<" "<<iArr[i];
    }

    int iWinSize;
    cout<<"\n Enter the sliding window size : ";
    cin>>iWinSize;

    int* iArrOutput;
    int iArrOutputSize;
    iArrOutputSize = iSize - iWinSize + 1;
    iArrOutput = new int[iArrOutputSize];

    FindMinInSlidingWindow(iArr, iSize, iWinSize, iArrOutput, iArrOutputSize);
    
    cout<<"\n Output array for minimum in sliding window :";            
    for(int i=0; i<iArrOutputSize; i++)
    {
        cout<<" "<<iArrOutput[i];
    }
    cout<<"\n";
    
    return 0;
}
