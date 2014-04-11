/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Print all the subsets of a string
// Complexity : O(N * 2^N)
/////////////////////////////////

#include <iostream>
#include <string>

using namespace std;


void PrintSubsets(string strInput, string strOutput, unsigned int iPos)
{
    
	if(iPos >= strInput.length())
	{
        if(strOutput.length() != 0)
        {
		    cout<<"\n "<<strOutput;
        }
	}
	else
	{
		PrintSubsets(strInput, strOutput, iPos+1);
		strOutput = strOutput + strInput[iPos];
		PrintSubsets(strInput, strOutput, iPos+1);
	}
}

int main()
{
    string strInput="";
    cout<<"\n Enter input string : ";
    cin>>strInput;
	string strOutput="";
	cout<<"\n Following are the subsets for '"<<strInput<<"' :-";
	PrintSubsets(strInput, strOutput, 0);
    cout<<"\n";
	
	return 0;
}
