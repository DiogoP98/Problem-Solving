#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int seq(vector<int> v,int pos) {

}

int main() {
	int n;

	while( scanf("%d", &n) != EOF ) {
		vector<int> values(n);


		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			values.push_back(x);
		}

		int longest = check seq(values, n-1);
	}
	
	return 0;
}