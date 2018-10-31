#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 10005

int n;
vector<int> bitree(MAX);

void update(int l, int r, int val) {
	for(int i = l; i <= r; i++) {
		i+=1;

		while(i <= n) {
			bitree[i] += val;

			i += i & (-i);
		}
	}

	for(int i = 1; i <= n; i++) printf ("%d: %d\n", i, bitree[i]);

	printf("\n");
}

int query(int i) {
	int sum = 0;
	i += 1;

	while(i > 0) {
		sum += bitree[i];

		i -= i & (-i);
	}

	return sum;
}


void build() {
	for(int i = 1; i <= n; i++) bitree[i] = 0; 
}

int main() {
	int t;

	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		int u;
		scanf("%d %d", &n, &u);
		build();
		for(int j = 0; j < u; j++) {
			int l, r, val;
			scanf("%d %d %d", &l, &r, &val);
			update(l,r,val);
		}

		int q;
		scanf("%d", &q);

		for(int j = 0; j < q; j++) {
			int index;
			scanf("%d", &index);
			int sum  = query(index);
			printf("%d\n", sum);
		}
	}

	return 0;
}