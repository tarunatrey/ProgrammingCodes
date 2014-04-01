/////////////////////////////////
// Author     : Tarun Atrey
// Date       : March 2014
// Copyright  : 2014 - Present
// Notes      : Count consecutive characters in a string
// Complexity : O(n)
/////////////////////////////////

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void CountConsecutiveChars(string str)
{
    int N;
    N = str.length();

    int flag, count, iDispChar, iCurrChar;

    cout<<(char)toupper(str[0]);
    iDispChar = toupper(str[0]);
    flag = 1;
    count = 1; 
    
    for(int i=1; i<N; i++)
    {
        iCurrChar = toupper(str[i]);

        if(iCurrChar == iDispChar)
        {
            count++;
        }
        else
        {
            cout<<count;
            cout<<(char)toupper(str[i]);
            iDispChar = iCurrChar;
            flag = 0;
            count = 1;
        }    
    }
    cout<<count;
}

int main()
{
    string str;
    cout<<"\n Enter a string : ";
    cin>>str;
    cout<<"\n Run Length Encoding : ";
    CountConsecutiveChars(str);
    cout<<"\n";    
    return 0;
}
