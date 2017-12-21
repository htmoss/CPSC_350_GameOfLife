#include <string>

using namespace std;

class Mirror: public Mode
{
public:
  Mirror();
  Mirror(int row, int col);
  ~Mirror();
  int alterGrid(char** grid, int row, int col);

private:
  int numRows;
  int numCols;
};
