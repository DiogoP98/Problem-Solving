#include <iostream>
#include <vector>

using namespace std;

int r,c;
vector<vector<int>> v(105);
vector<vector<int>> dp(105);


int calculate(int x, int y) {
	if(dp[x][y] != 0) return dp[x][y];

	dp[x][y] = 1;

	
	if(x-1 >=0) 
		if(v[x-1][y] < v[x][y]) dp[x][y] = max(calculate(x-1,y) + 1, dp[x][y]);

	if(x+1 < r) 
		if(v[x+1][y] < v[x][y]) dp[x][y] = max(calculate(x+1,y) + 1, dp[x][y]);

	if(y-1 >=0) 
		if(v[x][y-1] < v[x][y]) dp[x][y] = max(calculate(x,y-1) + 1, dp[x][y]);

	if(y+1 < c) 
		if(v[x][y+1] < v[x][y]) dp[x][y] = max(calculate(x,y+1) + 1, dp[x][y]);


	return dp[x][y];
}

int main() {
	int t;
	cin >> t;
	string name;
	for(int i = 0; i < t; i++) {
		string name;
		cin >> name;

		cin >> r >> c;

		for(int i = 0; i < r; i++) {
			v[i].resize(c+5);
			dp[i].resize(c+5);
			fill(dp[i].begin(),dp[i].end(), 0);
			for(int j = 0; j < c; j++)	cin >> v[i][j];
		}

		int ans = 0;

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				int c = calculate(i, j);
				//cout << c <<" " <<  i+1 << " " << j+1 << "  " << v[i][j] << endl;
				if(c > ans) ans = c;
			}
		}

		cout << name << ": " << ans << endl;
	}

	return 0;
}