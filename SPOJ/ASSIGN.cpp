/*
	Complexidade temporal: O(log(k)), k 
	Ajudas: https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
*/

#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 25
#define COMB (1<<20)

vector<vector<int>> v(MAX, vector<int>(MAX));
vector<long long int> dp(COMB);
int n, allmask;

long long int count(int mask) {
	long long int c = 0;

	while(mask != 0) {
		c += mask & 1;
		mask >>= 1;
	}

	return c;
}

long long int calculate(int mask) {

	long long int i = count(mask);


	if(i == n && mask == allmask) return 1;

	if(dp[mask] != -1) return dp[mask];

	dp[mask] = 0;

	for(int j = 0; j < n; j++) {
		if(v[i][j] == 1 &&  (mask & (1 << j))== 0) dp[mask] += calculate(mask | (1 << j));
	}

	return dp[mask];
}

int main() {
	int c;
	scanf("%d",&c);
	for(int i = 0; i < c; i++) {
		scanf("%d",&n);

		for(int j = 0; j < n; j++) 
			for(int k = 0; k < n; k++)
				scanf("%d",&v[j][k]);

		/*
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				printf("%d ", v[j][k]);
			}
		}
		*/

		fill(dp.begin(),dp.end(),-1);

		allmask = pow(2, n) - 1;

		long long int c = calculate(0);

		printf("%lld\n", c);
	}

	return 0;
}