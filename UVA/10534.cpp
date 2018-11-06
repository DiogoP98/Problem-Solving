#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void bsearch(vector<int>& num, vector<int>& index, int v, int pos) {
	int l = 0;
	int h = num.size()-1;

	while(l <= h) {
		int m = l + (h-l)/2;
		if(num[m] == v) {
			index[m] = pos;
			return;
		}

		if(num[m] > v) l = m+1;
		else h = m-1;
	}
	index[l] = pos;
	num[l] = v;
}

vector<int> lis(vector<int> v) {
	int size = (int) v.size();
	vector<int> index(size,-1);
	vector<int> num(size,-1);

	for(int i = size-1; i >= 0; i--) {

		if(v[i] > num[0]) {
			index[0] = i;
			num[0] = v[i];
		}
		else bsearch(num,index,v[i],i);

	}

	return index;
}

int main() {
	int n;

	while( scanf("%d", &n) != EOF ) {
		vector<int> values(n);


		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;

			values[i] = x;
		}

		vector<int> longest = lis(values);
		reverse(values.begin(), values.end());
		vector<int> longest2 = lis(values);

		int ans = 0;

		for(int i = 0; i < longest.size(); i++) {
			if(longest[i] == -1)
				break;

			if(longest[i] == longest2[i])
				ans = i+1;
		}

		if(ans == 0)
			ans = 1;

		cout << ans*2-1 << endl;
	}
	
	return 0;
}