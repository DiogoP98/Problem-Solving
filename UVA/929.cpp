/**

  Compleixdade: O(log(n*m)), onde n e o numero de linhas e m o numero de colunas

  Explicacao: Comecamos na posicao [0][0] e o objetivo e chegar a posicao [n-1][m-1], pelo menor caminho possivel.
              De maneira a obter esse mesmo caminho usamos o Dijkstra. Durante o algoritmo mantenmos um vector com
              o custo de cada no e uma priority queue que ordena os nos ja visitados pelo custo do caminho ate eles.
              Para cada no, vamos ver o custo do caminho ate cada um dos seus vizinhos. Se o custo do caminho ate um certo vizinho
              for maior do que o custo do no atual mais o valor do no vizinho, entao atualizamos o valor do custo do vizinho
              e adicionamo-lo a priority queue.
*/


#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

#define MAX 1005

int n,m;
vector<vector<int>> maze(MAX, vector<int>(MAX));

int dijkstra () {
  vector<vector<int>> custo(MAX, vector<int>(MAX, INT_MAX));
  priority_queue <pair <int, pair<int,int> >, vector <pair <int,pair<int,int>> >, greater <pair<int,pair<int,int>> > > pq;
  pq.push(make_pair(maze[0][0],make_pair(0,0)));
  custo[0][0]= maze[0][0];

  while (!pq.empty()) {
    pair<int,int> v = pq.top().second;
    int c = pq.top().first;
    pq.pop();

    int i = v.first;
    int j = v.second;

    if(i+1 < n) {
        if(custo[i+1][j] > c + maze[i+1][j]) {
          custo[i+1][j] = c + maze[i+1][j];
          pq.push(make_pair(custo[i+1][j], make_pair(i+1,j)));
        }
    }

    if(i-1 >= 0) {
        if(custo[i-1][j] > c + maze[i-1][j]) {
          custo[i-1][j] = c + maze[i-1][j];
          pq.push(make_pair(custo[i-1][j], make_pair(i-1,j)));
        }
    }

    if(j+1 < m) {
        if(custo[i][j+1] > c + maze[i][j+1]) {
          custo[i][j+1] = c + maze[i][j+1];
          pq.push(make_pair(custo[i][j+1], make_pair(i,j+1)));
        }
    }

    if(j-1 >= 0) {
        if(custo[i][j-1] > c + maze[i][j-1]) {
          custo[i][j-1] = c + maze[i][j-1];
          pq.push(make_pair(custo[i][j-1], make_pair(i,j-1)));
        }
    }
  }

  return custo[n-1][m-1];
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		cin >> n >> m;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> maze[i][j];
			}
		}

    int ans = dijkstra();
    cout << ans << endl;
	}	
}