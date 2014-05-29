/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Check if two given strings are one edit different (insertion, removal, replacement)
// Complexity : O(N) where N is the length of larger string
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;

bool CheckIfTwoStringsAreOneEditDiff(string strInput1, string strInput2)
{
    string strTemp;
    int iLen1, iLen2, iDiff;
    iLen1 = strInput1.length();
    iLen2 = strInput2.length();

    iDiff = iLen1 - iLen2;
    // 0   : Same length
    // +ve : First string is longer 
    // -ve : Second string is longer
   
    if(iDiff > 1)
    {
        return false;
    }
    else if(iDiff < -1)
    {
        return false;
    }

    if(iDiff == -1)
    {
        strTemp = strInput1;
        strInput1 = strInput2;
        strInput2 = strTemp;

        iDiff = iLen1;
        iLen1 = iLen2;
        iLen2 = iDiff;

        iDiff = -1;
    }

    for(int i=0,j=0; i<iLen1; i++,j++)
    {
        if(strInput1[i] != strInput2[j])
        {
            if(iDiff != 100 && iLen1 != iLen2)
            {
                j--;
                iDiff = 100;
            }
            else if(iDiff != 100 && iLen1 == iLen2)
            {
                iDiff = 100;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string strInput1, strInput2;

    cout<<"\n Enter the first input string : ";
    cin>>strInput1;
    cout<<"\n Enter the second input string : ";
    cin>>strInput2;
    
    if(CheckIfTwoStringsAreOneEditDiff(strInput1, strInput2))
    {
        cout<<"\n Given two strings are same or one edit different!\n";
    }
    else
    {
        cout<<"\n More than one edit different strings!\n";
    }

    return 0;
}
