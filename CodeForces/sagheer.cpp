#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,s;

	cin >> n >> s;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0, h = n;

	int max = 0;
	long long int min = 0;

	while(l < h) {
		int m = l + (h-l+1)/2;

		vector<long long int> u(n);
		long long int sum = 0;

		for (int i = 0; i < n; i++) {
			u[i] = (long long int) v[i] + (long long int)(i+1) * m;
		}

		sort(u.begin(),u.end());

		for (int i = 0; i < m; i++) {
			sum += u[i];
		}

		if(sum <= s){
			l = m;
			min = sum;
			max = m;
		}
		else
			h = m -1;
	}

	cout << max << " " << min << endl;

	return 0;
}