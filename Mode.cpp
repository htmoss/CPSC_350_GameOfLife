#include<string>
#include<iostream>
#include<fstream>
#include "Mode.h"
#include "Classic.h"
#include "Doughnut.h"
using namespace std;

//constructors
Mode::Mode()
{
  numRepeated = 0;
  currentCount = -1;
  cout<<"Mode has been created!"<<endl;
}

//destructor
Mode::~Mode()
{
  cout<<"Mode has been deleted!"<<endl;
}

//returns the name of the file
string Mode::getNameFile()
{
  return nameOfFile;
}

//returns number of rows
int Mode::getRows()
{
  return numRows;
}

//returns number of columns
int Mode::getCols()
{
  return numCols;
}
//sets rows
void Mode::setRows(int row)
{
  numRows = row;
}
//sets cols
void Mode::setCols(int col)
{
  numCols = col;
}

//Creates the first generation based off of file
char** Mode::buildFromFile(string fileName)
{
  ifstream gridFile;
  gridFile.open(fileName);
  gridFile>>numRows;
  gridFile>>numCols;
  cout<<"\nnumCols: "<<numCols<<"\nnumRows: "<<numRows<<endl;;

  char** grid1 = new char*[numRows];
  for (int r = 0; r < numRows; ++r)
  {
    grid1[r] = new char[numCols];
    for (int c = 0; c < numCols; ++c)
    {
      grid1[r][c] = ' ';
    }
  }

  for(int r = 0; r < numRows; ++r)
  {
    for(int c = 0; c < numCols; ++c)
    {
      grid1[r][c] = gridFile.get();
    }
    gridFile.get();
  }
  gridFile.close();
  return grid1;
}

//Creates the first generation randomly
char** Mode::buildFromRandom()
{
  cout << "How many rows?"<<endl;
  cin >> numRows;
  while(numRows <= 0)
  {
    cout<<"Please enter a positive integer."<<endl;
    cin >> numRows;
  }

  cout << "How many columns?"<<endl;
  cin >> numCols;
  while(numCols <= 0)
  {
    cout<<"Please enter a positive integer."<<endl;
    cin >> numCols;
  }
  double popDense;
  cout << "What would you like your population density to be? (A number between 0 and 1)"<<endl;
  cin >> popDense;
  while(popDense >= 1 || popDense <= 0)
  {
    cout<<"Please enter a DECIMAL between 0 and 1."<<endl;
    cin >> popDense;
  }

  //creates the grid
  char **grid1 = new char*[numRows];
  for (int i = 0; i < numRows; ++i)
  {
    grid1[i] = new char[numCols];
  }

  //calculate initial colony based on density input
  for (int r = 0; r < numRows; ++r)
  {
    for (int c = 0; c < numCols; ++c)
    {
      double randNum = rand();
			randNum = randNum / RAND_MAX;
			if (randNum < popDense)
      {
				grid1[r][c] = 'X';
      }
      else
      {
        grid1[r][c] = '-';
      }
    }
  }
  return grid1;
}

//asks which mode the user wants to play in
int Mode::askBoundary()
{
  int bound = 0;
  cout<<"What mode would you like to play in?"<<endl;
  cout<<"1.Classic\n2.Doughnut\n3.Mirror\n";
  cin>>bound;
  while (bound != 1 && bound != 2 && bound != 3)
  {
    cout << "Please enter 1, 2, or 3\n";
    cin >> bound;
  }
  return bound;
}

//asks user choice of output
string Mode::askOutputChoice()
{
  string outputChoice;
  cout << "Where would you like your output?\nPlease type \"console\" or the name of your file\n";
  cin >> outputChoice;
  return outputChoice;
}

//asks user if they want a type of delay
string Mode::askTime()
{
  string answer = "";
  cout << "Would you like to delay generations by pressing enter, a set delay, or none?\nPlease type \"enter\", \"delay\", or \"none\"\n";
  cin>>answer;
  while (answer != "enter" && answer != "delay" && answer != "none")
  {
    cout << "Please enter delay, none, or enter: ";
    cin >> answer;
  }
  return answer;
}

//prints out grid to console
void Mode::print(char** grid)
{
  for (int r = 0; r < numRows; ++r)
  {
    for (int c = 0; c < numCols; ++c)
    {
      cout << grid[r][c];
    }
    cout <<endl;
  }
  cout << "" << endl;
}

//prints out grid to a file
void Mode::print(char** grid, ofstream & output)
{
  for (int r = 0; r < numRows; ++r)
  {
    for (int c = 0; c < numCols; ++c)
    {
      output << grid[r][c];
    }
    output <<endl;
  }
  output << "" << endl;
}

//calculates what happens to square based on number of neighbors surrounding it
char Mode::liveOrDie(int num)
{
  if(num <= 1)//if 1 or 0, cell dies
  {
		return '-';
	}
	else if(num == 2)//if there are 2, remains stable
  {
		return '+';
	}
	else if(num == 3)//if there are 3, a cell grows
  {
		return 'X';
	}
	else//if there are more than 4, it dies
  {
		return '-';
	}
}

//checks if the game is in some sort of loop and its repeating itself
void Mode::checkRepeat(int c)
{
  if(c == currentCount)
  {
    ++numRepeated;
  }
  else
  {
    numRepeated = 0;
  }
  currentCount = c;
  if(numRepeated > 10000)
  {
    cout<<"Game seems to be repeating itself, terminating now"<<endl;
    exit(EXIT_FAILURE);
  }
}

//closing statement
void Mode::finish(int round)
{
  cout<<"\nGAME OVER.\nYour game lasted "<<round<<" rounds!\n\n";
}
