#include <iostream>
#include <vector>

using namespace std;

#define MAX 2e5+5

vector<string> sub(MAX);

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sub[i] = s;
	}

	

	return 0;
}