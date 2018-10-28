#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX 200005

vector<int> v(MAX);
vector<int> st(MAX);

int merge(int a, int b) {
	return a+b;
}

void build(int node, int start, int end) {
	if (start == end)
		st[node] = 1;

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);
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
	scanf("%d", &n);
	for(int  i = 0; i < n; i++) scanf("%d", &v[i]);
	vector<triple> queries(q);

	int position = 0;
	for(int i = 0; i < q; i++) {
		int a,b,k;
		scanf("%d %d %d", &a, &b, &k);
	}
	return 0;
}