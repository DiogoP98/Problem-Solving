#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longest(string s1, string s2) {
	vector< vector<int> > m(s1.size()+1);

	for (int i = 0; i <= s1.size(); i++) {
		m[i].resize(s2.size()+1);
		m[i][s2.size()] = 0;
	}

	for(int i = 0; i <= s2.size(); i++) {
		m[s1.size()][i] = 0;
	}

	for (int i = s1.size()-1; i >= 0; i--) {
		for(int j = s2.size()-1; j >=0 ; j--) {
			if(s1[i] == s2[j])
				m[i][j] = m[i+1][j+1] + 1;
			else {
				if (m[i][j+1] > m[i+1][j])
					m[i][j] = m[i][j+1];
				else
					m[i][j] = m[i+1][j];
			}
		}
	}

	return m[0][0];
}

int main() {
	string s1, s2;
	
	while (!getline(cin, s1).eof()) {
		getline(cin, s2);

		int x = longest(s1,s2);

		cout << x << endl;
	}
	
	return 0;
}