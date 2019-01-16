/**
	Complexidade: O(Klog(K)), K numero de estradas.
	
	Explicação: Começamos por guardar as ligações num vetor de pares e ordenamo-lo por ordem decrescente. Depois disto só precisamos de percorrer o vetor
	e ver quantas estradas anteriores a esta têm um nó terminal que seja menor do que o nó terminal da estrada atual.
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 1005

vector<long long int> bitree(MAX);
int n, m;


long long int query(int i) {
	long long int sum = 0;
	i+= 1;
	while(i  > 0) {
		sum += bitree[i];

		i -= i & (-i);
	}

	return sum;

}

void update(int i, int val) {
	i += 1;

	while (i <= m) {
		bitree[i] += val;

		i += i & (-i);
	}
}

void build () {

	for(int i  = 1 ; i <= m; i++) bitree[i] = 0;
}

int main() {
	int t;

	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		int k;
		scanf("%d %d %d", &n, &m, &k);
		build();
		vector<pair<int,int>> v(k+3);
		for(int j = 0; j < k; j++) {
			int v1, v2;
			scanf("%d %d", &v1, &v2);

			v.push_back(make_pair(v1,v2));			
		}

		sort(v.begin(), v.end(), greater<pair<int,int>>());
		long long int sum = 0;

		for(int j = 0; j < (int) v.size(); j++) {
			update(v[j].second,1);
			sum += query(v[j].second-1);
		}

		printf("Test case %d: %lld\n", i+1, sum);

	}
}