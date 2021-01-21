/**
	Complexidade: O(h*w), sendo h a altura e w a largura.
	
	Explicacao: Fazemos um floodfill, que percorre os vizinhos a partir de um no, e se o vizinho for igual ao no inicial, fazemos isso recursivamente
	para esse mesmo no. Verificamos isto para todos os nos que nao forem verificados, e cada vez que um no nao estiver visitado, 
	e tivermos que fazer um floodfill a partir deste, incrementamos em um o seu counter. Vamos depois criar um vetor de pairs, que contem
	a letra e o numero de estados. Ordenamos este array e depois e so imprimir. 
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

#define MAX 30

int w,h;
vector<vector<char>> adj(MAX, vector<char>(MAX));
vector<vector<bool>> visited(MAX, vector<bool>(MAX));
vector<int> counter(MAX);
vector<pair<char,int>> order;

void flood(int x, int y) {
	visited[x][y] = true;

	if(x + 1 < w && !visited[x+1][y]) {
		if(adj[x+1][y] == adj[x][y]) flood(x+1,y);
	}

	if(x - 1 >= 0 && !visited[x-1][y]) {
		if(adj[x-1][y] == adj[x][y]) flood(x-1,y);
	}

	if(y + 1 < h && !visited[x][y+1]) {
		if(adj[x][y+1] == adj[x][y]) flood(x,y+1);
	}

	if(y - 1 >= 0 && !visited[x][y-1]) {
		if(adj[x][y-1] == adj[x][y]) flood(x,y-1);
	}

	return;
}

bool compare(const pair<int,int> &a,  const pair<int,int> &b) {
	if(a.second == b.second) 
		return a.first < b.first;
		
	return a.second > b.second;
}

int main() {
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> w >> h;

		for(int j = 0; j < w; j++) {
			for(int k = 0; k < h; k++) {
				cin >> adj[j][k];
			}
		}

		for(int j = 0; j < w; j++) {
			for(int k = 0; k < h; k++) {
				if(!visited[j][k]) {
					counter[adj[j][k]-'a']++;
					flood(j,k);
				}
			}
		}

		cout << "World #" << i+1 << endl;


		for(int j = 0; j < MAX; j++)
			if(counter[j] != 0)
				order.push_back(make_pair((j+'a'), counter[j]));

		sort(order.begin(),order.end(), compare);

		for(int j = 0; j < (int) order.size(); j++) 
			cout << order[j].first << ": " << order[j].second << endl;
		
		fill(counter.begin(), counter.end(), 0);
		order.clear();

		for(int j = 0; j < MAX; j++) fill(visited[j].begin(), visited[j].end(), false);
	}
	return 0;
}