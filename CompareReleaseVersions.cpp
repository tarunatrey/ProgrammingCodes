/////////////////////////////////
// Author     : Tarun Atrey
// Date       : April 2014
// Copyright  : 2014 - Present
// Notes      : Compare release versions to tell which one is newer
// Complexity :
/////////////////////////////////

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int CompareReleaseVersion(string strVer1, string strVer2)
{
    string strArr1[20];
    string strArr2[20];
    string strTemp;
   
    int iNumOfTokens1, iNumOfTokens2;
    iNumOfTokens1 = 0;
    iNumOfTokens2 = 0;

    stringstream stream1(strVer1);
    while( getline(stream1, strTemp, '.') )
    {
        strArr1[iNumOfTokens1] = strTemp;
        iNumOfTokens1++;
    }
    
    stringstream stream2(strVer2);
    while( getline(stream2, strTemp, '.') )
    {
        strArr2[iNumOfTokens2] = strTemp;
        iNumOfTokens2++;
    }

    int iCount = 0;
    while(iNumOfTokens1>iCount && iNumOfTokens2>iCount)
    {
        iCount++;

        if( stoi(strArr1[iCount]) > stoi(strArr2[iCount]) )
        {
            return 1;
        }
        else if( stoi(strArr1[iCount]) < stoi(strArr2[iCount]) )
        {
            return 2;
        }    
    } 
    
    if(iNumOfTokens1 > iCount)
        return 1;
    else if(iNumOfTokens2 > iCount)
        return 2;
    else
        return 0;
}

int main()
{
    int iResult;
    string strVersion1, strVersion2;
    cout<<"\n Enter version numbers:-\n";
    cout<<"\n Version 1 : ";
    cin>>strVersion1;
    cout<<"\n Version 2 : ";
    cin>>strVersion2;

    iResult = CompareReleaseVersion(strVersion1, strVersion2);
    if(iResult != 0)
        cout<<"\n Release #"<<iResult<<" is newer version!\n";
    else
        cout<<"\n Both the versions are same"; 
    
    return 0;
}
