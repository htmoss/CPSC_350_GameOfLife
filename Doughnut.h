#include <string>

using namespace std;

class Doughnut:public Mode
{
public:
  Doughnut();
  Doughnut(int row, int col);
  ~Doughnut();
  int alterGrid(char** grid, int row, int col);

private:
  int numRows;
  int numCols;
};
