/**
	Complexidade: O(log(n) * q)
	Ajudas: https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
*/


#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 100005

int n;
vector<pair<long long int,long long int>> bitree(MAX);

void update(int p, long long int v) {
	while(p <= n) {
		bitree[p].first += v;
		p += p & (-p); 
	}
}

void update2(int p, long long int value1) {
	while(p <= n) {
		bitree[p].second += value1;
		p += p & (-p); 
	}
}

long long int sum(int q) {
	long long int soma = 0;  
   
    while (q>0) { 
        soma += bitree[q].first; 
  
        q -= q & (-q); 
    } 
    //printf("sum = %d\n", soma);
    return soma;
}

long long int sum2(int q) {
	long long int soma = 0; 
   
    while (q>0) { 
        soma += bitree[q].second; 
  
        q -= q & (-q); 
    } 
    //printf("sum2 = %d\n", soma);
    return soma;
}


void build() {
	for(int i = 1; i <= n; i++) bitree[i] = make_pair(0,0);
}

int main() {
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		int c;
		scanf("%d %d", &n, &c);
		build();
		for(int j = 0; j < c; j++) {
			int op;
			scanf ("%d", &op);
			int p, q;
			if(op == 0) {
				int v;
				scanf("%d %d %d", &p, &q, &v);
				//printf("%d %d %d\n", p, q, v);
				update(p,v);
				update(q+1,-v);
				update2(p,(long long int) -v*(p-1));
				update2(q+1,(long long int)v*q);
			}
			else {
				scanf("%d %d", &p, &q);
				//printf("%d %d\n", p, q);
				//printf("query 1 : %d %d\n", query(q-1),query(p-2));
				long long int soma = sum(q) * q + sum2(q) - sum(p-1) * (p-1) - sum2(p-1);
				printf ("%lld\n", soma);
			}
		}
	}
}