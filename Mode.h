#include <string>
#include <iostream>
using namespace std;

class Mode
{
public:
  Mode();
  ~Mode();
  string getNameFile();
  int getRows();
  int getCols();
  void setRows(int row);
  void setCols(int col);
  void printGrid(char**grid);
  char** buildFromFile(string fileName);
  char** buildFromRandom();
  int askBoundary();
  string askOutputChoice();
  string askTime();
  void print(char** grid);
  void print(char** grid, ofstream & output);
  char liveOrDie(int num);
  void checkRepeat(int c);
  void finish(int round);


private:
  string nameOfFile;
  int numRows;
  int numCols;
  bool isFromFile;
  int numRepeated;
  int currentCount;
};
