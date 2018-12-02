#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n+5);
	vector<bool> c(n+5,false);
	for(int i = 0; i < n; i++) cin >> v[i];
	int k = 0;

	for(int i = 1; i < n-1; i++) {
		if(v[i-1]==1 && v[i+1] == 1 && v[i] != 1 && !c[i-1] && !c[i+1]) { 
			k++;
			c[i-1] = true;
			c[i+1] = true;
		}
	}

	cout << k << endl;

	return 0;
}