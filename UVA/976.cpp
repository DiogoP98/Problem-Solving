/**
	Complexidade: O(R*C), sendo r o numero de linhas e c o numero de colunas.

	Explicacao: Comecamos por fazer dois flood-fill de maneira a encontrarmos as margens superior e inferior.
	Depois, utilizando dp, onde para cada posicao e cada numero de pontes restantes vamos calcular o minimo. Para o minimo de cada uma
	destas posicoes temos duas hipoteses: colocar uma ponte nessa posicao x, que liga as margens superiores e inferiores desse mesmo x
	e calcular o custo de colocar b-1 pontes, a partir da poiscao atual - s, sendo s a distancia necessaria entre pontes. Outra hipotese
	e nao colocar a ponte na posicao atual e calcular a partir dai


*/

#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <string>


#define MAX 10*10*10*10*10*10*10*10
#define MAXR 10005
#define MAXB 105
using namespace std;

vector<vector<int>> limits(2);
bool visited[MAXR][MAXR];
vector<vector<int>> map(MAXR, vector<int>(MAXR));
vector<vector<int>> dp(MAXR, vector<int>(MAXB));

int r, c, b, s;

void floodfill(int x, int y, int pos) {
	visited[x][y] = true;

	if(pos == 0)
		limits[pos][y] = max(limits[pos][y],x);
	else
		limits[pos][y] = min(limits[pos][y],x);

	if(x-1>=0)
		if(map[x-1][y] == 1 && !visited[x-1][y]) floodfill(x-1,y,pos);

	if(y-1 >= 0)
		if(map[x][y-1] == 1 && !visited[x][y-1]) floodfill(x,y-1,pos);

	if(y+1 < c)
		if(map[x][y+1] == 1 && !visited[x][y+1]) floodfill(x,y+1,pos);

	if(x+1 < r)
		if(map[x+1][y] == 1 && !visited[x+1][y]) floodfill(x+1,y,pos);
}

int calculate(int pos, int b2) {
	if(pos < 0) {
		if(b2 == 0) return b2;
		else return MAX-5;
	}

	if(dp[pos][b2] != MAX) return dp[pos][b2];

	if(b2 == 0)
		dp[pos][b2] = 0;
	else
		dp[pos][b2] = min(dp[pos][b2], min(calculate(pos-s-1,b2-1)+limits[1][pos]-limits[0][pos]-1,calculate(pos-1,b2)));
	
	return dp[pos][b2];
}

int main() {
	while(scanf("%d %d %d %d", &r,&c,&b,&s) != EOF) {

		for(int i = 0; i < r; i++) {
			fill(map[i].begin(),map[i].end(),0);
			char op[c+5];
			scanf("%s", op);
			for(int j = 0; j < c; j++) {
				if(op[j] == '#') map[i][j] = 1;
				visited[i][j] = false;
			}
		}

		limits[0].resize(c+5);
		limits[1].resize(c+5);

		for(int i = 0; i < c; i++) {
			fill(dp[i].begin(),dp[i].end(),MAX);
			limits[0][i] = 0;
			limits[1][i] = r;
		}

		floodfill(0,0,0);
		floodfill(r-1,0,1);

		int ans = calculate(c-1,b);

		printf("%d\n", ans);

	}
	
	return 0;
}