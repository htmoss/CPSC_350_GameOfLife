#include<string>
#include<iostream>
#include<fstream>
#include "Mode.h"
#include "Classic.h"

using namespace std;

//constructors
Classic::Classic()
{
  cout<<"Classic has been created!"<<endl;
}
Classic::Classic(int row, int col)
{
  numRows = row;
  numCols = col;

  cout<<"Classic has been created!"<<endl;
}

//destructors
Classic::~Classic()
{
  cout<<"Classic has been deleted!"<<endl;
}

//plays a round of the grid
int Classic::alterGrid(char** grid, int row, int col)
{
  int n = 0;
  for (int j = row - 1; j <= row + 1; ++j)
  {
    for (int k = col - 1; k <= col + 1; ++k)
    {
      if(j >= getRows())
        continue;
      if(k >= getCols())
        continue;
      if(j < 0)
        continue;
      if(k < 0)
        continue;
      if((j == row) && (k == col))
        continue;
      else
      {
        if (grid[j][k] == 'X')
          n++;
      }
    }
  }
  return n;
}
