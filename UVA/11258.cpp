#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void calculate(string s) {
	int n = (int) s.length();
	long long int sum = 0;

	vector<long long int> dp(n+5);

	for(int i = 0; i < n; i++) {
		sum = 0;
		for(int j = i; j < n; j++) {
			sum = sum*10 + (int) s[j]-'0';
			if(sum > INT_MAX) break;
			dp[j+1] = max(dp[j+1],dp[i] + sum);
		}
	}

	printf("%lld\n", dp[n]);
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;

		calculate(s);
	}

	return 0;
}