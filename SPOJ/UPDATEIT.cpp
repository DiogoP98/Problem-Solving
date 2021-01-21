/**
	Complexidade: O(logn). 
	
	Explicação: Para fazermos range update, vamos atualizar todos os nós pais de l e r, e depois subtrair o valor que adicionamos aos nós que são maiores que r, ou seja,
	que não pertencem ao intervalo.
	A operação de query é uma sum normal em BITs.
*/


#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 10005

int n;
vector<int> bitree(MAX);

void update(int l, int r, int val) {
	while(l <= n) {
		bitree[l] += val;
		l += l & (-l); 
	}

	r+=1;
	
	while(r <= n) {
		bitree[r] -= val;
		r += r & (-r);
	}
}

int query(int i) {
	i+= 1;
	int sum = 0;
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
			update(l+1,r+1,val);
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