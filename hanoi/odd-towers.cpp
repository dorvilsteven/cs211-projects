// Towers of Hanoi (Odd)- Steven Dorvil
#include <iostream>
#include<vector>

using namespace std;

int main() {
  vector<int> t[3];
  int n, candidate, from, to, move=0;

  cout << "Enter an odd number: ";
  cin >> n;

  // make sure n is odd
  while(n%2==0) {
    cout << "Please enter an odd number: ";
    cin >> n;
  }
  cout << endl;

  // initialize 3 towers
  for (int i=n+1;i>0;i--)
    t[0].push_back(i);

  t[1].push_back(n+1);
  t[2].push_back(n+1);

  // INITAL SETTING OF TOWERS
  cout << "Initial tower setting" << endl;
  for (int i=0;i<3;i++) {
    int x = t[i].back();
    cout << x << " ";
  }
  cout << endl << endl;
  // initialize towers and candidate
  from = 0, to = 1, candidate = 1;

  // if t[1].size()  == 4, then stop!
  while(t[1].size() < n+1) {
    // write it
    cout << "move #" << ++move << endl;
    cout << "Transer " << candidate << " from tower " << char(from+65) << " to " << char(to+65) << endl;

    // do it
    t[to].push_back(t[from].back());
    t[from].pop_back();

    // change the from tower
    if (t[(to+1)%3].back() < t[(to+2)%3].back())
      from = (to+1)%3;
    else
      from = (to+2)%3;

    // change the to tower
    if (t[from].back() < t[(from+1)%3].back())
      to = (from+1)%3;
    else
      to = (from+2)%3;

    // get new candidate
    candidate = t[from].back();

    int x = t[0].back();
    int y = t[1].back();
    int z = t[2].back();
    cout << x << " " << y << " " << z << endl << endl;
  }

  // fINAL SETTING OF TOWERS
  cout << "Final tower setting " << endl;
  for (int i=0;i<3;i++) {
    int x = t[i].back();
    cout << x << " ";
  }
  cout << endl;


  return 0;
}
