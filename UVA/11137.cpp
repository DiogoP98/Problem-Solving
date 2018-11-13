#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int n;
vector<int> coins(25);

void calculate() {
	vector<long long int> cal(n+5,0);

	cal[0] = 1;

	for(int i = 1; i <= 21; i++) {
		for(int j = coins[i]; j <= n; j++) cal[j] = (long long int)cal[j] + cal[j-coins[i]];
	}

	printf("%lld\n", cal[n]);
}

int main() {
	for(int i = 1; i <= 21; i++) coins[i] = i*i*i;

	while(scanf("%d", &n) != EOF) calculate();

	return 0;
}