/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2016
// Copyright  : 2016 - Present
// Notes      : Rearrange an array containing equal no. of even and odd integers, such that evens are at even places and odds are at odd places. 
// Complexity : O(N)
/////////////////////////////////

#include <iostream>

using namespace std;

void RearrangeArray(int iArr[], int iNum)
{
    int iEvenIndex, iOddIndex, iEvenIndexFlag, iOddIndexFlag, iTempNum;
    iEvenIndex = 1;
    iOddIndex = 0;
    iEvenIndexFlag = 0;
    iOddIndexFlag = 0;

    while(iEvenIndex < iNum && iOddIndex < iNum)
    {
        if(iArr[iEvenIndex]%2 == 0)
        {
            //Number is even
            iEvenIndex += 2;
            iEvenIndexFlag = 0;
        }
        else
        {
            iEvenIndexFlag = 1;
        }

        if(iArr[iOddIndex]%2 == 1)
        {
            //Number is odd
            iOddIndex += 2;
            iOddIndexFlag = 0;
        }
        else
        {
            iOddIndexFlag = 1;
        }

        if(iEvenIndexFlag == 1 && iOddIndexFlag == 1)
        {
            iTempNum = iArr[iEvenIndex];
            iArr[iEvenIndex] = iArr[iOddIndex];
            iArr[iOddIndex] = iTempNum;
            iEvenIndex += 2;
            iOddIndex += 2;
        }
    }
}

void PrintArray(int iArr[], int iNum)
{
    for(int i=0; i<iNum; i++)
    {
        cout<<iArr[i]<<" ";
    }
    cout<<"\n";
}

int main()
{
    int iArr[] = {2, 1, 3, 4, 7, 9, 24, 98};
    int iNumOfElements;

    iNumOfElements= sizeof(iArr)/sizeof(int);

    //Print original array
    cout<<"\nOriginal array: ";
    PrintArray(iArr, iNumOfElements);

    //Rearrange arary with even and odd numbers at respective places
    RearrangeArray(iArr, iNumOfElements);

    //Print rearranged array
    cout<<"\nRearranged array: ";
    PrintArray(iArr, iNumOfElements);

    return 0;
}
