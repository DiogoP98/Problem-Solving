#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n+6);
	int max = 0;
	for(int i = 0; i < n; i++) cin >> v[i];

	int count = 0;
	
	if(n==1) printf("0\n");
	else if(v[n-1] == n) printf("%d\n", n-1);
	else {
		for(int i  = 1; i < n; i++) {
			if(i < n-1) {
				if(v[i+1] - v[i-1] == 2) count++;
				else count = 0;
			}
			else {
				if(v[i-1] == 999) count++;
				else count = 0;
			}

			if(count > max) max = count;
		}
		printf("%d\n", max);
	}

	return 0;
}