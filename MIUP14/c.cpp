#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,r;

void check_count(vector<int> roles, vector<int> count, vector<int> max, vector<int> min, int pos, int players) {
	for (int i = pos; i <= n; i++) {
		if (min[i] != -1) {
			roles[i] = min[i];
		}

		if (max[i] != -1) {

		}
	}
}


int main() {
	cin >> n >> r;

	vector<int> roles(r);
	vector<int> count(r);

	vector<int> max(r,-1);
	vector<int> min(r,-1);
	for (int i = 0; i < r; i++) {
		string m;
		int x;
		cin >> m >> x;

		if (m == "MIN")
			min[i] = x;

		else
			max[i] = x; 
	}

	check_count(roles,count,max,min, 0,0);

	return 0;
}