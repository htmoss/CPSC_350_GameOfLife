#include <string>
#include <iostream>
using namespace std;

class Classic: public Mode
{
public:
  Classic();
  Classic(int row, int col);
  ~Classic();
  int alterGrid(char** grid, int row, int col);

private:
  int numRows;
  int numCols;
};
