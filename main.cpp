#include<string>
#include<iostream>
#include<fstream>
#include "Mode.h"
#include "Classic.h"
#include "Doughnut.h"
#include "Mirror.h"
#include <unistd.h>

using namespace std;

int main(int argc, char** argv)
{
  cout<<"I'm working!"<<endl;

  Mode m1;
  char** grid1;
  int answer;

  cout<<"Would you like to\n1. Start with a random configuration\n2. Specify a file configuration"<<endl;
  cin>>answer;
  if(answer!=2 && answer!=1)
  {
    cout<<"Please run program again and enter either 1 or 2"<<endl;
    exit (EXIT_FAILURE);
  }
  else
  {
    //from file
    if(answer == 2)
    {
      cout<<"What is the name of your file?"<<endl;
      string nameOfFile;
      cin >> nameOfFile;
      cout<<"nameOfFile is: "<<nameOfFile;
      grid1 = m1.buildFromFile(nameOfFile);
    }
    //from console
    else
    {
      grid1 = m1.buildFromRandom();
    }
  }

  int boundary;
  boundary = m1.askBoundary();
  string outputChoice = "";
  string time = "";
  outputChoice = m1.askOutputChoice();
  time = m1.askTime();
  int count;
  int n;
  char t;

  //creating second 2d array for use
  char** grid2 = new char*[m1.getRows()];
  for (int i = 0; i < m1.getRows(); ++i)
  {
    grid2[i] = new char[m1.getCols()];
  }
  for (int r = 0; r < m1.getRows(); ++r)
  {
    for (int c = 0; c < m1.getCols(); ++c)
    {
      grid2[r][c] = '-';
    }
  }

  int round = 1;

  if(boundary == 1)//CLASSIC
  {
    Classic c1;
    c1.setCols(m1.getCols());
    c1.setRows(m1.getRows());
    if(outputChoice == "console")
    {
      cout<<endl;
      c1.print(grid1);
    }
    else
    {
      ofstream outfile(outputChoice);
      outfile<<endl;
      c1.print(grid1, outfile);
      outfile.close();
    }
    ofstream outfile(outputChoice);

    while (true)
    {
      cout<<"ROUND "<<round<<endl<<endl;
      count = 0;
      for (int r = 0; r < c1.getRows(); ++r)
      {
        for (int c = 0; c < c1.getCols(); ++c)
        {
          n = c1.alterGrid(grid1, r, c);
          t = c1.liveOrDie(n);

          if (t == '+')
            grid2[r][c] = grid1[r][c];//remains stable
          else
            grid2[r][c] = t;//either grows or dies
        }
      }

      for (int r = 0; r < c1.getRows(); ++r)
      {
        for (int c = 0; c < c1.getCols(); ++c)
        {
          if (grid2[r][c] != grid1[r][c])
          {
            count++; //counting number of changes
          }
        }
      }
      cout<<"count: "<<count<<endl<<endl;
      m1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }

      for (int r = 0; r < c1.getRows(); ++r)
      {
        for (int c = 0; c < c1.getCols(); ++c)
        {
          grid1[r][c] = grid2[r][c]; //copying new grid onto old
        }
      }

      if (outputChoice == "console")
      {
        c1.print(grid1);
      }
      else
      {
        c1.print(grid1, outfile);
      }
      if (time == "delay")
      {
        sleep(1);
      }
      else if (time == "enter")
      {
        cin.get();
      }
      ++round;
    }
    outfile.close();
  }
  else if(boundary == 2) //DOUGHNUT
  {
    cout<<"Doughnut mode selected."<<endl;
    Doughnut d1;
    d1.setCols(m1.getCols());
    d1.setRows(m1.getRows());
    if(outputChoice == "console")
    {
      cout<<endl;
      d1.print(grid1);
    }
    else
    {
      ofstream outfile(outputChoice);
      d1.print(grid1, outfile);
      outfile.close();
    }
    ofstream outfile(outputChoice);

    while (true)
    {
      cout<<"ROUND "<<round<<endl<<endl;
      count = 0;
      for (int r = 0; r < d1.getRows(); ++r)
      {
        for (int c = 0; c < d1.getCols(); ++c)
        {
          n = d1.alterGrid(grid1, r, c);
          t = d1.liveOrDie(n);

          if (t == '+')
            grid2[r][c] = grid1[r][c];//remains stable
          else
            grid2[r][c] = t;//either grows or dies
        }
      }

      for (int r = 0; r < d1.getRows(); ++r)
      {
        for (int c = 0; c < d1.getCols(); ++c)
        {
          if (grid2[r][c] != grid1[r][c])
          {
            count++; //counting number of changes
          }
        }
      }
      cout<<"count: "<<count<<endl<<endl;
      m1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }

      for (int r = 0; r < d1.getRows(); ++r)
      {
        for (int c = 0; c < d1.getCols(); ++c)
        {
          grid1[r][c] = grid2[r][c]; //copying new grid onto old
        }
      }

      if (outputChoice == "console")
      {
        d1.print(grid1);
      }
      else
      {
        d1.print(grid1, outfile);
      }
      if (time == "delay")
      {
        sleep(1);
      }
      else if (time == "enter")
      {
        cin.get();
      }
      ++round;
    }
    outfile.close();
  }
  else //MIRROR
  {
    cout<<"Mirror mode selected."<<endl;
    Mirror mirr1;
    mirr1.setCols(m1.getCols());
    mirr1.setRows(m1.getRows());
    if(outputChoice == "console")
    {
      cout<<endl;
      mirr1.print(grid1);
    }
    else
    {
      ofstream outfile(outputChoice);
      mirr1.print(grid1, outfile);
      outfile.close();
    }
    ofstream outfile(outputChoice);

    while (true)
    {
      cout<<"ROUND "<<round<<endl<<endl;
      count = 0;
      cout<<"rows: "<<mirr1.getRows();
      cout<<"cols: "<<mirr1.getCols();
      for (int r = 0; r < mirr1.getRows(); ++r)
      {
        for (int c = 0; c < mirr1.getCols(); ++c)
        {
          n = mirr1.alterGrid(grid1, r, c);
          t = mirr1.liveOrDie(n);

          if (t == '+')
            grid2[r][c] = grid1[r][c];//remains stable
          else
            grid2[r][c] = t;//either grows or dies
        }
      }

      for (int r = 0; r < mirr1.getRows(); ++r)
      {
        for (int c = 0; c < mirr1.getCols(); ++c)
        {
          if (grid2[r][c] != grid1[r][c])
          {
            count++; //counting number of changes
          }
        }
      }
      cout<<"count: "<<count<<endl<<endl;
      m1.checkRepeat(count);
      if (count == 0)
      {
        break;
      }

      for (int r = 0; r < mirr1.getRows(); ++r)
      {
        for (int c = 0; c < mirr1.getCols(); ++c)
        {
          grid1[r][c] = grid2[r][c]; //copying new grid onto old
        }
      }

      if (outputChoice == "console")
      {
        mirr1.print(grid1);
      }
      else
      {
        mirr1.print(grid1, outfile);
      }
      if (time == "delay")
      {
        sleep(1);
      }
      else if (time == "enter")
      {
        cin.get();
      }
      ++round;
    }
    outfile.close();
  }
  m1.finish(round);

  for (int i = 0; i < m1.getRows(); i++)
  {
    delete[] grid1[i];
  }
  delete[] grid1;
  for (int i = 0; i < m1.getRows(); i++)
  {
    delete[] grid2[i];
  }
  delete[] grid2;









  return 0;
}
