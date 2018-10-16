#include <iostream>

using namespace std;

void check_count(vector<int> e, int ni,int count, int pos, int nbs, int nas) {
	if(pos == 0)
		return;

	

}

int main() {
	int n;

	cin >> n;

	for (int i =0; i < n; i++) {
		int ni, ki;
		cin >> ni >> ki;

		vector<int> e(ni);
		e[n-1] = 1;
		check_count(e,ni,0,ni-1,1,1);
	}
	return 0;
}