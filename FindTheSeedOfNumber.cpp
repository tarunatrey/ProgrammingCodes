/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Find the seed of a given number
// Complexity : O(N), N is the number
/////////////////////////////////

#include <iostream>
#include <cmath>

using namespace std;

int FindSeedOfNumber(int iNum)
{
    // Seed will always will greater than sqrt(iNum) and less than iNum/2
    
    if(iNum == 1)
    {
        return 1;
    }

    int iProduct, iSeed, iTemp;
    iProduct = 1;
    iSeed = (int) sqrt(iNum);

    while(iSeed < iNum/2)
    {
        iProduct = iSeed;
        iTemp = iSeed;

        while(iTemp > 0)
        {
            iProduct = iProduct * (iTemp%10);
            iTemp = iTemp/10;
        }        
        
        if(iProduct == iNum)
        {
            return iSeed;
        }
        iSeed++;      
    }

    return -1;
}

int main()
{
    int iNum, iSeed;

    cout<<"\n Enter the number : ";
    cin>>iNum;

    iSeed = FindSeedOfNumber(iNum);

    if(iSeed != -1)
    {
        cout<<"\n Seed of the given number : "<<iSeed<<"\n";
    }
    else
    {
        cout<<"\n There is no seed for the given number!\n";
    }

    return 0;
}
