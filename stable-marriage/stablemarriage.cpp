// Stable Marriage - Steven Dorvil CS211
#include<iostream>
using namespace std;

bool ok(int q[], int col) { // Finish this code
	static int mp[3][3] = {
							{ 0,2,1 },  // Man#0's preferences
							{ 0,2,1 },	// Man#1's preferences
							{ 1,2,0 } 	// Man#2's preferences
						};

	static int wp[3][3] = {
							{ 2,1,0 },	// Woman#0's preferences
							{ 0,1,2 },	// Woman#1's preferences
							{ 2,0,1 } 	// Woman#2's preferences
						};
	for (int i=0;i<col;i++) {
		if (q[col]==q[i]) return false;
	}
	for (int j=0;j<col;j++) {
		if( (mp[col][q[j]]) < (mp[col][q[col]]) && (wp[q[j]][col]) < (wp[q[j]][j]) ) return false;
		if( (wp[q[col]][j]) < (wp[q[col]][col]) && (mp[j][q[col]]) < (mp[j][q[j]]) ) return false;
	}
	return true;
}

void print(int q[]) {
	static int count = 0;
	cout << "Solution #" << ++count << endl;
	//Finish this print function
	cout << "Man\tWoman" << endl;
	for (int i=0;i<3;i++) {
		cout << i << "\t" << q[i] << endl;
	}
	cout << endl;
}


int main() {
	int q[3];
	int c=0;
	q[c]=0;

	while(c<3){
		c++;
		if (c==3) {
			print(q);
			c--;
		} else {
			q[c]=-1;
		}
		while(q[c]<3){
			q[c]++;
			if (q[c]==3) {
				c--;
			} else {
				if(ok(q, c)) break;
			}
		}
		// cout << "code by steven dorvil cs211" << endl;
		if (c==-1) return 0;
	}
	return 0;
}
