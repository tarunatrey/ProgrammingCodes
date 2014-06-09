/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Sort two sorted arrays in place
// Complexity : O(M+N^2), where M is the number of elements in first array and N in second array
/////////////////////////////////

#include <iostream>

using namespace std;

void SortTwoSortedArrays(int iArr[], int iSize)
{
    int iTemp;

    for(int i=1; i<iSize; i++)
    {
        if(iArr[i-1] < iArr[i])
        {
            continue;
        }
        else
        {
            iTemp = iArr[i];
            for(int j=i-1; j>=0; j--)
            {
                if(iArr[j] > iTemp)
                {
                    iArr[j+1] = iArr[j];
                    if(j==0)
                    {
                        iArr[j] = iTemp;
                    }
                } 
                else
                {
                    iArr[j+1] = iTemp;
                    break;
                }
            }
        }
    }

    cout<<"\n Full sorted array :";
    for(int i=0; i<iSize; i++)
    {
        cout<<" "<<iArr[i];
    }
}

int main()
{
    int iArr[] = {3, 5, 8, 9, 15, 2, 4, 13, 14, 21};

    int iSize;
    iSize = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :";            
    for(int i=0; i<iSize; i++)
    {
        cout<<" "<<iArr[i];
    }

    SortTwoSortedArrays(iArr, iSize);

    cout<<"\n";

    return 0;
}
