/*

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

#define MAX 1000

int n;
vector<int> coins = {5,10,20,50,100,200};

int calculate2(int value) {
	vector<int> cal(value+5, MAX);

	cal[0] = 0;
	for(int i = 1; i <= value; i++) {
		for(int j = 0; j < 6; j++) {
			if(coins[j] <= i) cal[i] = min(cal[i], cal[i-coins[j]] + 1); 
		}
	}

	return cal[value];
}

void calculate(vector<int> q) {
	vector<int> cal(n+5,MAX);

	cal[0] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 6; j++) {
			for(int k = 1; k <= q[j]; k++) {
				if(coins[j] * k > i) cal[i] = min(k + calculate2(-(i-coins[j]*k)), cal[i]);
				else cal[i] = min(cal[i-coins[j]*k] + k , cal[i]);
			}
		}
		printf("here\n");
	}
	printf("%d\n", cal[n]);
}

int main() {
	vector<int> q(10);
	double v;

	scanf("%d %d %d %d %d %d", &q[0], &q[1], &q[2], &q[3], &q[4], &q[5]);

	while(scanf("%lf", &v) != EOF) {
		v*= 100;
		n = (int)v;
		printf("%d\n",n);
		calculate(q);
		scanf("%d %d %d %d %d %d", &q[0], &q[1], &q[2], &q[3], &q[4], &q[5]);
	}

	return 0;
}