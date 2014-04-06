/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Replace an element with the following closest element bigger than it
// Complexity : O(n^2)
/////////////////////////////////

#include <iostream>

using namespace std;

void ReplaceArrElements(int iArr[], int N)
{
    int i, j;

    for(i=0; i<N-1; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(iArr[i] < iArr[j])
            {
                iArr[i] = iArr[j];
                break;
            }
        }
    }
}

int main()
{
    int iArr[] = {2, 12, 8, 6, 5, 1, 2, 10, 3, 2};
    int N;
    N = sizeof(iArr)/sizeof(iArr[0]);

    cout<<"\n Original array :     ";  
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }

    ReplaceArrElements(iArr, N);

    cout<<"\n Regenerated array : ";            
    for(int i=0; i<N; i++)
    {
        cout<<" "<<iArr[i];
    }
    cout<<"\n";

    return 0;
}
