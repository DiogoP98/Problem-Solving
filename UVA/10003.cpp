#include <iostream>
#include <vector>

using namespace std;

#define MAXC 55
#define MAXL 10005
#define FILL 10000

vector<int> c(MAXC);
vector<vector<int>> dp(MAXL, vector<int>(MAXL));
int n, l;

int calculate(int pos, int size) {
	if(size-pos == 1) return 0;

	if(dp[pos][size] != -1) return dp[pos][size];

	dp[pos][size] = FILL;

	for(int i = pos; i < pos+size - 1; i++)
		dp[pos][size] = min(dp[pos][size], calculate(pos,i) + calculate(i,pos+size-1) + c[size]- c[pos]);

	return dp[pos][size];
}

int main() {
	cin >> l;

	while(l != 0) {
		cin >> n;

		for(int i = 1; i <= n; i++) cin >> c[i];

		for(int i = 0; i < l; i++) fill(dp[i].begin(),dp[i].end(), -1);

		int ans = calculate(1,l);

		cout << "The minimum cutting is " << ans << endl;

		cin >> l;
	}

	return 0;
}