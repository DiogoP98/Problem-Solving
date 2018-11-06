#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

void lcs(vector<string> v1, vector<string> v2) {
	vector<vector<int>> m(v1.size()+5);
	vector<string> ans;

	for(int i = 0; i <= (int) v1.size(); i++) {
		m[i].resize(v2.size()+5);
		m[i][0] = 0;
	}

	for(int i = 0; i <= (int) v2.size(); i++) m[0][i] = 0;

	for(int i = 1; i <= (int) v1.size(); i++) {
		for(int j = 1; j <= (int) v2.size(); j++) {
			if(v1[i-1] == v2[j-1]) m[i][j] = m[i-1][j-1] + 1;
			else m[i][j] = max(m[i][j-1], m[i-1][j]);
		}
	}

	int i = (int) v1.size(), j = (int) v2.size();

	while(i > 0 && j > 0) {
		if(v1[i-1] == v2[j-1]) {
			ans.push_back(v1[i-1]);
			i--; j--; 
		}

		else if(m[i-1][j] > m[i][j-1]) i--;
		else j--;
	}

	for(i = (int) ans.size() - 1; i >= 0; i--) {
		if(i == 0 ) cout << ans[i] << endl;
		else cout << ans[i] << " ";
	}
}

int main() {
	vector<string> v1;
	vector<string> v2;

	string s;

	while(cin >> s) {
		v1.clear();
		v2.clear();
		
		v1.push_back(s);

		string s2;
		cin >> s2;
		while(s2 != "#") {
			v1.push_back(s2);
			cin >> s2;
		}

		cin >> s2; 
		while(s2 != "#"){
			v2.push_back(s2);
			cin >> s2;
		}

		lcs(v1,v2);
	}
	return 0;
}