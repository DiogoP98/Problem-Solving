#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

int calculate(int i, int maxa, int maxb, vector<int> track, vector<int>& dp, int v) {
	if(dp[i] != INT_MAX) return dp[i];

	for(int j = maxa; j >=-maxb; j-=10) {
		cout << "here" << endl;
		if(v/10+j+i < (int) track.size()) {
			if(v+j*10 <= track[i+v/10+j]) {
				dp[i] = calculate(i+v/10+j,maxa,maxb,track,dp,v+j*10) + 1;
			}
			else
				dp[i] = 10000;
		}
	}

	return dp[i];
}

int main() {
	int c;
	cin >> c;

	for(int i = 0; i < c; i++) {
		int maxa, maxb;
		cin >> maxa >> maxb;

		vector<int> track;
		int n, v;
		cin >> n >> v;
		while(n!= 0 || v!=0) {
			for(int j = 0; j < n; j++) track.push_back(v);
			cin >> n >> v;
		}

		//for(int j = 0; j < track.size(); j++) cout << track[j] << endl;

		vector<int> dp(track.size()+5,INT_MAX);
		int minc = 0;

		for(int i = 0; i < maxa/10; i++) {
			int c = calculate(i,maxa,maxb,track,dp,i*10);
			if(c > minc) minc = c;
		}

		//for(int j = 0; j < track.size(); j++) cout << dp[j] << " ";

		//cout << endl;

		cout << minc << endl;
	}

	return 0;
}