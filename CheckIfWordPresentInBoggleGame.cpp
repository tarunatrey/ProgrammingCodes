/////////////////////////////////
// Author     : Tarun Atrey
// Date       : June 2014
// Copyright  : 2014 - Present
// Notes      : Check if a given word is present in a boggle game 2D array of chars
// Complexity : O(N^2 + (M-1)* 3^2) where N is number of rows & cols in 2D matrix AND M is number of letters in input string
/////////////////////////////////

#include <iostream>
#include <string>
#define iRow 4
#define iCol 4

using namespace std;

int iArrVisited[iRow][iCol];

bool CheckWordRecursive(char cArr[][iCol], int iRowPointer, int iColPointer, string strInput, int iStrPointer)
{
    for(int i=iRowPointer-1; i<=iRowPointer+1; i++)
    {
        for(int j=iColPointer-1; j<=iColPointer+1; j++)
        {
            if(i>=0 && i <=(iRow-1) && j>=0 && j<=(iCol-1) && iArrVisited[i][j]==0)
            {
                if(cArr[i][j] == strInput[iStrPointer])
                {
                    iArrVisited[i][j] = 1;
                    if(iStrPointer == (strInput.length()-1))
                    {
                        return true;
                    }
                    if(CheckWordRecursive(cArr, i, j, strInput, ++iStrPointer))
                    {
                        return true;
                    }
                    else
                    {
                        iArrVisited[i][j] = 0;
                    }
                }
            }
        }   
    }
    return false;
}
    
bool CheckWordPresent(char cArr[][iCol], string strInput)
{   
    for(int i=0; i<iRow; i++)
    {
        for(int j=0; j<iCol; j++)
        {
            if(cArr[i][j] == strInput[0])
            {
                iArrVisited[i][j] = 1;
                if(CheckWordRecursive(cArr, i, j, strInput, 1))
                {
                    return true;
                }
                else
                {
                    iArrVisited[i][j] = 0;
                }
            }
        }
    }

    return false;
}

int main()
{
    string strInput;
    char cArr[iRow][iCol] = {   {'B','A','R','T'},
                                {'D','K','P','S'},
                                {'Y','E','U','T'},
                                {'E','O','R','N'}  };

    cout<<"\n Original 2D array for Boggle :-\n\n";            
    for(int i=0; i<iRow; i++)
    {
        for(int j=0; j<iCol; j++)
        {
            cout<<" "<<cArr[i][j];
        }
        cout<<"\n";
    }

    //Populate iArrVisited
    for(int i=0; i<iRow; i++)
    {
        for(int j=0; j<iCol; j++)
        {
            iArrVisited[i][j] = 0;
        }
    }

    cout<<"\n Enter the input word : ";
    cin>>strInput;

    if(CheckWordPresent(cArr, strInput))
    {
        cout<<"\n Input word is present in 2D array!\n";
        
        cout<<"\n Array visited :-\n";
        for(int i=0; i<iRow; i++)
        {
            for(int j=0; j<iCol; j++)
            {
                cout<<" "<<iArrVisited[i][j];
            }
            cout<<"\n";
        }
    }
    else
    {
        cout<<"\n Input word is not present in 2D array!\n";
    }
       
    return 0;
}
