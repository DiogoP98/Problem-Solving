/**
	Complexidade: O(n*m), n numero de items e m o orcamento.

	Explicacao: Se o orcamento for menor ou igual do que 1800, signifca que ela nao pode ter o bonus de 200$, pois o total das compras
	nunca pode ultrapassar a 2000$. No entanto se for maior do que 1800, se por exemplo ela tive 1801$ e fizer uma compra de 2001$,
    vai receber os 200$ extra e com estes consegue fazer a compra.
    Para o primeiro caso, so precisamos de ver qual e o numero maximo de favour index que ela pode comprar com cada valor. Para isso,
    vamos percorrer todos os valores possiveis, e se com esse valor ela conseguir comprar um item, entao, para esse valor o numero maximo de favour index
    vai ser o favour index desse item, mais o valor máximo que se pode obter com orcamento restante.

*/


#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF) {
		int orim = m;
		
		if(m > 1800)
			m += 200;

		vector<int> v(m+5,0);
		vector<pair<int,int>> items(n+5);

		for(int i = 1; i <= n; i++) {
			int size, val;
			scanf("%d %d" ,&size, &val);
			items[i] = make_pair(size,val);
		}

		for(int i= 1; i <= n; i++) {
			for(int j = m; j - items[i].first >= 0; j--) {
				if(v[j - items[i].first] > 0 || j == items[i].first) v[j] = max(v[j], v[j-items[i].first] + items[i].second);
	 		}
		}

		int ans = 0;
   		 for (int i = 1; i <= m; i++) {
   		 	if (orim > 2000 || i < orim || i > 2000) ans = max(ans, v[i]);
    	}

    	printf("%d\n", ans);
	}

	return 0;
}