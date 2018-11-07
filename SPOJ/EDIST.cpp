#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int n;

	cin >> n;

	for(int i = 0; i < n; i++) {
		string a, b;

		cin >> a >> b;
		int asize = a.length();
		int bsize = b.length();

		vector<vector<int>> v(asize+5);

		for(int i = 0; i <= asize; i++) { 
			v[i].resize(bsize+5);
			v[i][0] = i;
		}

		for(int i = 0; i <= bsize; i++) v[0][i] = i;

		for(int i = 1; i <= asize; i++) {
			for(int j = 1; j <= bsize; j++) {
				int value;
				if(a[i-1] == b[j-1])  value = 0;
				else value = 1;
				v[i][j] = min(v[i-1][j-1] + value, min(v[i-1][j]+1,v[i][j-1]+1));
			}
		}

		cout << v[asize][bsize] << endl;
	}
	return 0;
}