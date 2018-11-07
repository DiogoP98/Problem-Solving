#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int s, n;
	cin >> s >> n;

	vector<int> v(s+5);
	vector<pair<int,int>> m(n+5);

	for(int i = 0; i <= s; i++) v[i] = 0;

	for(int i = 1; i <= n; i++) {
		int size, val;
		cin >> size >> val;
		m[i] = make_pair(size,val);
	}

	for(int i= 1; i <= n; i++) {
		for(int j = s; j >= 0; j--) {
			if(m[i].first <= j) v[j] = max(v[j], v[j-m[i].first] + m[i].second);
 		}
	}

	cout << v[s] << endl;

	return 0;
}