/**
	Complexidade: O(log(n) * e), sendo n o numero de edificios, e "e" o numero de ruas.

	Explicacao: Aplicamos o algoritmo de Prim, de maneira a obter a arvore de peso minimo. Isto e, a arvore, tal que todos os nos estao ligados,
	e o custo total de todas as ligacoes e o minimo. Depois, de o obter o custo, neste caso o tamanho da rua, basta multiplicar pelo custo de cada 
	furlong e obtemos o custo total. 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define MAX 1005

int p,n,m;
vector<pair<int,int>> adj[MAX];

int prim() {
  vector<int> dist(n, INT_MAX);
  vector<bool> inMST(n,false);
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

  pq.push(make_pair(0,0));
  dist[0]=0;
  int t = 0;

  while (!pq.empty()) {
    int node = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    if(inMST[node])
    	continue;

    inMST[node] = true;
    t+= cost;
      
	for (int i= 0 ;i < (int)adj[node].size() ; i++) {
		int v = adj[node][i].second;
		int weight = adj[node][i].first;
		
		if (inMST[v]==false && weight < dist[v]) {
	  		dist[v] = weight;
	  		pq.push(make_pair(dist[v],v));
		}
    }
  }

  return t;
}

int main() {
	int t;
	cin >> t;

	for(int i = 0; i < t; i++) {
		cin >> p >> n >> m;

		int v1, v2, c;
		for(int i = 0; i < m; i++) {
			cin >> v1 >> v2 >> c;
			adj[v1-1].push_back(make_pair(c,v2-1));
			adj[v2-1].push_back(make_pair(c,v1-1));
		}

		int ans = prim();

		cout << ans*p << endl;

		for(int i = 0; i < n; i++)
			adj[i].clear();
	}

	return 0;
}