#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000005

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
		st[node] = freq[start];

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);		
	}

	//printf("%d [%d,%d] = %d\n", node, start, end, st[node]);
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
			lbound[j] = start;
		}

		build(1,1,n);

		for(int i = 0; i < q; i++) {
			int x, y;
			cin >> x >> y;
			int l1=0, l2=0; 

			if(rbound[x] == rbound[y]) {
				cout << y-x+1 << endl;
				continue;
			}

			if(x <= rbound[x])
				l1 = rbound[x] - x + 1;

			if(y >= lbound[y])
				l2 = y - lbound[y] + 1;

			int k = query(1,1,n,rbound[x]+1,lbound[y]-1);
			int a = max(k, max(l2,l1));

			cout << a << endl;
		}
	}


	return 0;
}