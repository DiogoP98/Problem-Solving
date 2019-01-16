#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 1000005

string s;
vector<int> f(MAX);
int n;

void failure() {
	int j = -1;
	f[0] = -1;
	for(int i = 1; i < n; i++) {
		while(j > -1 && s[j+1] != s[i])j = f[j];

		if(s[j+1] == s[i]) j++;

		f[i] = j;
	}
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> n;
		cin >> s;

		cout << "Test case #" << i+1 << endl;
		failure();
		for(int j = 0; j < n; j++) {
			if(f[j] > -1 && (j+1)%(j+1-f[j]-1) == 0) cout << j+1 << " " << (j+1)/(j+1-f[j]-1) << endl;
		}

		cout << endl;
	}

	return 0;
}