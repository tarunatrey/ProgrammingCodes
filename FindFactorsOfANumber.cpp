/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Find all the factors of a given number 
// Complexity : O(N)
/////////////////////////////////

#include <iostream>

using namespace std;

void FindFactorsOfANumber(int iNum)
{
    int iFactor=2;
    int iTempNum;
    iTempNum = iNum;

    while(iFactor <= iNum)
    {
        while(iTempNum%iFactor == 0)
        {
            cout<<iFactor<<" ";
            iTempNum = iTempNum/iFactor;
        }
        iFactor++;
    }
}

int main()
{
    int iNum;

    cout<<"\n Enter the number : ";
    cin>>iNum;
    
    cout<<"\n Factors : ";
    FindFactorsOfANumber(iNum);
    cout<<"\n";    

    return 0;
}
