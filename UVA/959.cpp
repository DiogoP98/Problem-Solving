#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

int size, maxa,maxb;

#define MAX 5000000
#define MAXN 10005
#define MAXB 500

vector<vector<int>> dp(MAXN,vector<int>(MAXB));
vector<int> track(MAXN);

int calculate(int i, int v) {
	if(dp[i][v] != MAX) return dp[i][v];

	for(int j = maxa; j >=-maxb; j-=10) {
		if((v+j)/10+i+1 <= size && v+j > 0) {
			bool pos = true;

			for(int k = i+1; k < i+1+(v+j)/10; k++) {
				if(v+j > track[k]) { 
					pos = false;
					break;
				}
			}

			if(pos) dp[i][v] = min(calculate(i+(v+j)/10,v+j) + 1,dp[i][v]);
			else dp[i][v] = MAX-5;
		}

		else if((v+j)/10+i+1 > size){
			bool pos = true;
			for(int k = i+1; k < size; k++) {
				if(v+j > track[k]){  
					pos = false;
					break;
				}
			}

			if(pos) {
				dp[i][v] = 1;
				break;
			}
			else dp[i][v] = MAX-5;
		}
	}

	return dp[i][v];
}

int main() {
	int c;
	cin >> c;

	for(int i = 0; i < c; i++) {
		cin >> maxa >> maxb;

		int n, v; 
		size=1;
		cin >> n >> v;
		track[0] = 0;
		while(n!= 0 || v!=0) {
			for(int j = size; j < size+n; j++) track[j] = v;
			size+=n;
			cin >> n >> v;
		}

		for(int j = 0; j < size; j++) fill(dp[j].begin(),dp[j].end(),MAX);
		

		int c = calculate(0,0);

		//for(int j = 0; j < size; j++)cout << j << "= " << dp[j] << endl;

		cout << c << endl;
		//cout << "--------------"<< endl;
	}

	return 0;
}