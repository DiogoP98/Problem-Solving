#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>

using namespace std;

int size, maxa,maxb;

int calculate(int i, vector<int> track, vector<int>& dp, int v) {
	if(dp[i] != INT_MAX) return dp[i];

	for(int j = maxa; j >=-maxb; j-=10) {
		//cout << "i=" << i << " v= " << v << " result=" << (v+j)/10+i << "  n=" << size << endl;

		if((v+j)/10+i+1 < size && v+j >=0) {
			bool pos = true;
			for(int k = i+1; k < i+1+(v+j)/10; k++) {
				if(v+j > track[k]){ 
					//cout << "entrou" << endl; 
					pos = false;
					break;
				}
			}
			if(pos) {
				//cout << "here     " << i+(v+j)/10 << endl;  
				dp[i] = min(calculate(i+(v+j)/10,track,dp,v+j) + 1,dp[i]);
			}
		}
		else if((v+j)/10+i+1 >= size){
			bool pos = true;
			for(int k = i+1; k < size; k++) {
				if(v+j > track[k]){  
					pos = false;
					break;
				}
			}
			if(pos) {
				//cout << "here2" << endl;
				dp[i] += 1;
				break;
			}
		}
	}

	return dp[i];
}

int main() {
	int c;
	cin >> c;

	for(int i = 0; i < c; i++) {
		cin >> maxa >> maxb;

		vector<int> track;
		int n, v;
		cin >> n >> v;
		track.push_back(0);
		while(n!= 0 || v!=0) {
			for(int j = 0; j < n; j++) track.push_back(v);
			cin >> n >> v;
		}

		//for(int j = 0; j < track.size(); j++){ cout << track[j] << " ";cout << endl;}
		

		size = (int) track.size() - 1;
		vector<int> dp(n+5,INT_MAX);

		int c = calculate(0,track,dp,0);

		for(int j = 0; j < size; j++)cout << j << "= " << dp[j] << endl;

		cout << endl;

		cout << dp[0] << endl;
		//cout << "--------------"<< endl;
	}

	return 0;
}