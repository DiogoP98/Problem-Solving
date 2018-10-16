#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n,s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, c;

		cin >> s >> c;

		vector<int> v(5000000);

		for (int i = 0; i < s; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.begin()+s);

		int l = 0, h = pow(10,9);

		int mm;

		while(l < h) {
			int m = l + (h-l+1)/2;

			
			int fs = v[0];
			int ncows = 1;
			for (int j = 1; j < s; j++) {
				if(v[j] - fs >= m) {
					ncows++;
					fs = v[j];
				}
			}

			if(ncows >= c){
				mm = m;
				l = m;
			}

			else
				h = m -1;
		}

		cout << mm << endl;
	}

	return 0;
}