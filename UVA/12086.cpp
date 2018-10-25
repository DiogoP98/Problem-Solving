#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000005

vector<int> v(MAX);
vector<int> st(MAX);

int merge(int a, int b) {
	return a+b;
}

void build(int node, int start, int end) {
	if (start == end)
		st[node] = v[start];

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);
	}
}

int query(int node, int start, int end, int x, int y) {
	if (y < start  || end < x) return 0;

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

	int n;

	int c = 1;

	while(true) {
		scanf("%d", &n);
		if(n == 0) break;
		if (c > 1) printf("\n");

		for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
		printf("Case %d:\n", c++);
		build(1,1,n);
		char op[5];
		while(true) {
			scanf("%s", op);


			if(op[0] == 'S'){
				int x, val;
				scanf("%d %d", &x, &val);
				update(1,1,n,x,val);
			}else if(op[0] == 'M'){
				int x, y;
				scanf("%d %d", &x, &y);
				int r = query(1,1,n,x,y);
				printf ("%d\n", r);
			}else if(strcmp(op, "END") == 0) break;
		}
	}

	return 0;
}