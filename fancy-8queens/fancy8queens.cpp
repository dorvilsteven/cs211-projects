// Fancy Eight Queens - Steven Dorvil
#include <iostream>
#include <cmath>
using namespace std;

void print(int q[]) {
  int i,j,k,l;
  typedef char box[5][7];
  box bb, wb, *board[8][8];

  // fill in boxes
  for (i=0;i<5;i++) {
    for (j=0;j<7;j++) {
      bb[i][j] = ' ';
      wb[i][j] = char(219);
    }
  }
  // white queen
  static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                    {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                    {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                    {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}
  };
  // black queen
  static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                    {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                    {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                    {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      }
  };

  // fill in board
  for (i=0;i<8;i++)
    for (j=0;j<8;j++)
      if ((i+j)%2==0)
        board[i][j] = &wb;
      else
        board[i][j] = &bb;

  // place black queen on white background
  // place white queen on black background
  for (i=0;i<8;i++)
      if ((i+q[i])%2==0)
        board[i][q[i]] = &bq;
      else
        board[i][q[i]] = &wq;

  // print upper border
   cout << ' ' << ' ';
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << endl;

  // print the chessboard
  for (i=0;i<8;i++)
    for (k=0;k<5;k++) {
      cout << " " << char(179);
      for (j=0;j<8;j++)
        for (l=0;l<7;l++)
          cout << (*board[i][j])[k][l];
      cout << char(179) << endl;
    }

    // print lower border
     cout << ' ' << ' ';
     for (i=0; i<7*8; i++)
        cout << char(196);
     cout << endl << endl;
}

bool ok(int q[], int c) {
  for (int i=0;i<c;i++)
    if (q[i]==q[c] || (c-i) == (abs(q[c]-q[i]))) return false;
  return true;
}

void queens(int q[], int c) {
  if (c==8)
    print(q);
  else for(q[c] = 0; q[c] < 8; ++q[c])
      if (ok(q, c))
        queens(q, c+1);
}

int main() {
  int q[8] = {0};
  queens(q, 0);
  return 0;
}
