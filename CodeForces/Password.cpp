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
		while(j > -1 && s[j+1] != s[i]) j = f[j];

		if(s[j+1] == s[i]) j++;

		f[i] = j;
	}

}

int main() {
	cin >> s;
	n = (int) s.length();
	failure();

	int result = f[n-1];

	//for(int i = 0; i < n; i++) cout << f[i] << "  ";cout << endl;

	while(result > -1) {
		bool found = false;
		for(int i = 0; i < n - 1; i++) {
			if(f[i] == result) {
				found = true;
				break;
			}
		}
		if(found) break;
		result = f[result];
	}

	if(result == -1)
		printf("Just a legend\n");
	else {
		for(int i = 0; i <= result; i++) printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}