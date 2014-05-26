/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Check if an input number is a palindrome
// Complexity : O(N), check each element once
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

bool CheckIfNumberIsPalindrome(int iNum)
{
    int iRevNum, iIndex, iTemp;
    iIndex = 0;
    iRevNum = 0;

    if(iNum < 0)
        iNum = iNum * (-1);
    iTemp = iNum;
    
    while(iTemp > 0)
    {
        iRevNum = iRevNum * 10 + iTemp%10;
        iTemp = iTemp/10;
    }
    
    return (iRevNum == iNum);
}

int main()
{
    int iNum;

    cout<<"\n Enter the number : ";
    cin>>iNum;
    
    if(CheckIfNumberIsPalindrome(iNum))
    {
        cout<<"\n Input number is a palindrome!\n";
    }
    else
    {
        cout<<"\n Input number is not a palindrome!\n";
    }

    return 0;
}
