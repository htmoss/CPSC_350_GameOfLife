#include<string>
#include<iostream>
#include<fstream>
#include "Mode.h"
#include "Mirror.h"
using namespace std;

//constructors
Mirror::Mirror()
{
  cout<<"Mirror has been created!"<<endl;
}

Mirror::Mirror(int row, int col)
{
  numCols = col;
  numRows = row;
  cout<<"Mirror has been created!"<<endl;
}
//deconstructor
Mirror::~Mirror()
{
  cout<<"Mirror has been celeted!"<<endl;
}

//plays a round of the grid
int Mirror::alterGrid(char** grid, int row, int col)
{
  int n = 0;
  if (row == 0)
  {
    if (col == 0) // top left
    {
      if (grid[0][0] == 'X')
        n += 3;
      if (grid[1][0] == 'X')
        n += 2;
      if (grid[1][1] == 'X')
        n += 1;
      if (grid[0][1] == 'X')
        n += 2;
    }
    if (col == getCols() - 1) // top right
    {
      if (grid[0][getCols() - 1] == 'X')
        n += 3;
      if (grid[1][getCols() - 1] == 'X')
        n += 2;
      if (grid[1][getCols() - 2] == 'X')
        n += 1;
      if (grid[0][getCols() - 2] == 'X')
        n += 2;
    }
    else // top row
    {
      if (grid[0][col] == 'X')
        n++;
      if (grid[0][col + 1] == 'X')
        n += 2;
      if (grid[0][col - 1] == 'X')
        n += 2;
      for (int below = col - 1; below <= col + 1; ++below)
        if (grid[1][below] == 'X')
          n++;
    }
  }
  if (row == getRows() - 1)
  {
    if (col == 0) // bottom left
    {
      if (grid[getRows() - 1][0] == 'X')
        n += 3;
      if (grid[getRows() - 2][0] == 'X')
        n += 2;
      if (grid[getRows() - 2][1] == 'X')
        n += 1;
      if (grid[getRows() - 1][1] == 'X')
        n += 2;
    }
    if (col == getCols() - 1) // bottom right
    {
      if (grid[getRows() - 1][getCols() - 1] == 'X')
        n += 3;
      if (grid[getRows() - 2][getCols() - 1] == 'X')
        n += 2;
      if (grid[getRows() - 2][getCols() - 2] == 'X')
        n += 1;
      if (grid[getRows() - 1][getCols() - 2] == 'X')
        n += 2;
    }
    else // bottom row
    {
      if (grid[getRows() - 1][col] == 'X')
        n++;
      if (grid[getRows() - 1][col + 1] == 'X')
        n += 2;
      if (grid[getRows() - 1][col - 1] == 'X')
        n += 2;
      for (int top = col - 1; top <= col + 1; ++top)
        if (grid[getRows() - 2][top] == 'X')
          n++;
    }
  }
  if ((col == 0) && (row> 0) && (row< getRows() - 1)) // left side
  {
    if (grid[row - 1][0] == 'X')
      n += 2;
    if (grid[row+ 1][0] == 'X')
      n += 2;
    if (grid[row][0] == 'X')
      n++;
    for (int right = row- 1; right <= row+ 1; ++right)
      if (grid[right][1] == 'X')
        n++;
  }
  if ((col == getCols() - 1) && (row> 0) && (row< getRows() - 1)) // right side
  {
    if (grid[row- 1][getCols() - 1] == 'X')
      n += 2;
    if (grid[row+ 1][getCols() - 1] == 'X')
      n += 2;
    if (grid[row][getCols()-1] == 'X')
      n++;
    for (int right = row- 1; right <= row+ 1; ++right)
      if (grid[right][getCols() - 2] == 'X')
        n++;
  }
  if ((col > 0) && (col < getCols() - 1) && (row > 0) && (row < getRows() - 1)) // middle of grid
  {
    for (int j = row-1; j <= row+ 1; ++j)
    {
      for (int k = col-1; k <= col + 1; ++k)
      {
        if ((j == row) && (k == col))
          continue;
        else
        {
          if (grid[j][k] == 'X')
            n++;
        }
      }
    }
  }
  return n;
}
