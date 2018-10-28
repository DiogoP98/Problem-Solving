#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 20000005

vector<int> v(MAX);
vector<int> st(MAX);

int merge(int a, int b) {
	return a*b;
}

void build(int node, int start, int end) {
	if (start == end) {
		st[node] = v[start];
	}

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);
	}

	//cout << "node: " << node << "  " << start << "," << end << "     :" << st[node] << endl;
}

int query(int node, int start, int end, int x, int y) {
	if (y < start  || end < x) return 1;

	if(start>=x && end <= y) return st[node];

	int m = start + (end-start)/2;
	int a = query(node*2, start, m, x, y);
	int b = query(node*2+1, m+1, end, x, y);

	return merge(a,b);
}

void update(int node, int start, int end, int x, int k) {
	if(start == end) 
		st[node] = k;

	else {
		int m = start + (end - start)/2;

		if(start <= x && x <= m) 
			update(2*node, start, m, x, k);
		else
			update(2*node+1, m+1, end, x, k);

		st[node] = merge(st[2*node],st[2*node+1]);
	}
}

int main() {

	int n, k;

	while(scanf("%d", &n) != EOF) {
		scanf("%d", &k);

		for(int i = 1; i <= n ; i++){ 
			scanf("%d", &v[i]);
			if(v[i] > 0) v[i] = 1;
			else if(v[i] < 0) v[i] = -1;
			else v[i] = 0;
		}

		//cout << v[10] << endl;

		build(1,1,n);

		for(int i = 0; i < k; i++) {
			char s[2];
			scanf("%s",s);
			int y,l;

			if(s[0] == 'C') {
				cin >> y >> l;
				if(l > 0) l = 1;
				else if(l < 0) l = -1;
				else l = 0;

				//if(y >=9 && y <=11) cout << "   here " << y << " " << l << "p value: " << v[y] << "it: " << i+1 << endl;

				if(l != v[y]) {
					update(1,1,n,y,l);
					v[y] = l;
				}
			}

			else {
				cin >> y >> l;
				int p = query(1,1,n,y,l);
				if (p < 0) printf("-");
				else if(p > 0) printf("+");
				else printf("0");
			}
		}
		cout << endl;
	}

	return 0;
}