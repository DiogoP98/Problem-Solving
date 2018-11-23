#include <iostream>
#include <vector>

using namespace std;

#define MAXC 55
#define MAXL 10005
#define FILL 10000

vector<int> c(MAXC);
vector<vector<int>> dp(MAXL, vector<int>(MAXC));
int n, l;

int calculate(int pos, int cut,int size) {
	if(dp[pos][cut] != FILL) return dp[pos][cut];

	for(int i = 0; i < n; i++) {
		dp[pos][cut] = min(dp[pos][cut], calculate(pos+c[i]-1,c[i], size-c[i]) + size);
	}

	return dp[pos][cut];
}

int main() {
	cin >> l;

	while(l != 0) {
		cin >> n;

		for(int i = 0; i < n; i++) cin >> c[i];

		for(int i = 0; i < l; i++) fill(dp[i].begin(),dp[i].end(), FILL);

		int ans = calculate(0,0, l);

		cout << "The minimum cutting is " << ans << endl;

		cin >> l;
	}

	return 0;
}