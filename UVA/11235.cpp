#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000005

vector<int> v(MAX);
vector<int> st(MAX);
vector<int> freq(MAX);
vector<int> lbound(MAX);
vector<int> rbound(MAX);

int merge(int a, int b) {
	return max(a,b);
}

void build(int node, int start, int end) {
	if (start == end)
		st[node] = 1;

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);

		if(lbound[start] == lbound[end])
			st[node] = max(st[node], );

		if(lbound[end] > lbound[start]) {
			int fs = rbound[start]-start+1;
			int ss = end-lbound[end]+1;
			if (start == 6 && end == 7) {
				cout << ss << " " << fs << endl;
			}
			st[node] = max(st[node], max(fs,ss));
		}
	}

	printf("%d [%d,%d] = %d\n", node, start, end, st[node]);
}

int query(int node, int start, int end, int x, int y) {
	if (y < start  || end < x) return 0;

	if(start>=x && end <= y) return st[node];

	int m = start + (end-start)/2;
	int a = query(node*2, start, m, x, y);
	int b = query(node*2+1, m+1, end, x, y);

	return merge(a,b);
}

int main() {
	int n, q;

	while(true) {
		cin >> n >> q;

		if(n == 0) break;

		for(int i = 1; i <= n ; i++) cin >> v[i];

		int count = 1;
		int start = 1;
		for(int i = 1; i < n ; i++) {
			if (v[i] != v[i+1]) {
				for(int j = i ; j >= start; j--) { 
					freq[j] = count;
					rbound[j] = i;
					lbound[j] = start;
				}
				count = 1;
				start = i+1;
			}
			else count++;
		}

		for(int j = n ; j >= start; j--) { 
			freq[j] = count;
			rbound[j] = n;
			rbound[j] = start;
		}

		for(int j = 1 ; j <= n; j++) cout << freq[j] << endl;

		build(1,1,n);

		for(int i = 0; i < q; i++) {
			int x, y;
			cin >> x >> y;
			//int k = query(1,1,n,x,y);


			//cout << k << endl;
		}
	}


	return 0;
}