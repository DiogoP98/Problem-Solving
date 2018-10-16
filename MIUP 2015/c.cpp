#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n,k;

	cin >> n >> k;

	vector<int> pos(n);
	vector<int> next(n);

	for (int i = 0; i < n; i++) {
		pos[i] = i+1;

		next[i] = pos[(i+k)%n];
	}

	cout << next[0] << endl;


	return 0;
}