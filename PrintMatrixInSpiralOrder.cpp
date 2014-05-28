/////////////////////////////////
// Author     : Tarun Atrey
// Date       : May 2014
// Copyright  : 2014 - Present
// Notes      : Print a matrix in spiral order 
// Complexity : O(N)
/////////////////////////////////

#include <iostream>

#define iRow 4
#define iCol 4

using namespace std;

void PrintMatrix(int iMatrix[][iCol], int iR, int iC)
{
    cout<<"\n Matrix :- \n";
    for(int i=0; i<iR; i++)
    {
        for(int j=0; j<iC; j++)
        {
            if(iMatrix[i][j] < 10)
            {
                cout<<" ";
            }
            cout<<" "<<iMatrix[i][j];
        }
        cout<<"\n";
    }
}

void PrintMatrixInSpiralOrder(int iMatrix[][iCol], int iR, int iC)
{
    int iLeft, iRight, iTop, iBottom;
    iLeft = 0;
    iRight = iC - 1;
    iTop = 0;
    iBottom = iR - 1;

    int iIndex = 0;
    int* iArr;
    iArr = new int[iR*iC];

    int i;

    cout<<"\n Matrix printed in spiral order of parsing :- \n";
    while( iLeft < iRight && iTop < iBottom )
    {
        //Print top row
        for(i=iLeft; i<=iRight; i++)
        {
            cout<<" "<<iMatrix[iTop][i];
        }
        iTop++;

        //Print right column
        for(i=iTop; i<=iBottom; i++)
        {
            cout<<" "<<iMatrix[i][iRight];
        }
        iRight--;
        
        //Print bottom row
        for(i=iRight; i>=iLeft; i--)
        {
            cout<<" "<<iMatrix[iBottom][i];
        }
        iBottom--;
        
        //Print left column    
        for(i=iBottom; i>=iTop; i--)
        {
            cout<<" "<<iMatrix[i][iLeft];
        }
        iLeft++;
    }
    cout<<"\n";
}

int main()
{
    int iMatrix[iRow][iCol];

    int iCount;
    iCount = 1;

    for(int i=0; i<iRow; i++)
    {
        for(int j=0; j<iCol; j++)
        {
            iMatrix[i][j] = iCount++;
        }
    }

    PrintMatrix(iMatrix, iRow, iCol);
    PrintMatrixInSpiralOrder(iMatrix, iRow, iCol);
    
    return 0;
}
