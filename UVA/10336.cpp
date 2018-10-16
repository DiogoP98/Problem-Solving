#include <iostream>
#include <vector>
#include <map>


using namespace std;

int w,h;
int ar[26];

void checkComp(char c, int i, int j,vector< vector<int> > comp, vector< vector<char> >& m,int n) {

	if(i-1>=0 && m[i-1][j]==c) {
		comp[i-1][j] == n;
		checkComp(c,i-1,j,comp,m,n);
	}

	if(j-1>=0 && m[i][j-1]==c) {
		comp[i][j-1] == n;
		checkComp(c,i,j-1,comp,m,n);
	}

	if(i+1<w && m[i+1][j]==c) {
		comp[i+1][j] == n;
		checkComp(c,i+1,j,comp,m,n);
	}

	if(j+1<h && m[i][j+1]==c) {
		comp[i][j+1] == n;
		checkComp(c,i,j+1,comp,m,n);
	}
} 


int main() {
	int n; 

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> w >> h;
		vector< vector<char> > m(w);
		vector< vector<int> > comp(w);

		for (int j = 0; j < w; j++) {
			m[j].resize(h);
			comp[j].resize(h);

			for (int k = 0; k < h; k++) {
				cin >> m[j][k];
				comp[j][k] = -1; 
			}
		}

		int num = 0;
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < h; k++) {
				if (comp[j][k] == -1) {
					checkComp(m[j][k], j, k, comp, m, num);
					ar[(int)m[j][k]-'a']++;
					num++;
				}

			}
		}
	}

	return 0;
}