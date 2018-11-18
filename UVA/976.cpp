#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdlib>
#include <string>


#define MAX 10*10*10*10*10*10*10*10
#define MAXR 10005
using namespace std;

vector<vector<int>> limits(2);
bool visited[MAXR][MAXR];

int r, c, b, s;

void floodfill(int x, int y, vector<vector<int>> map,int pos) {
	visited[x][y] = true;

	if(pos == 0)
		limits[pos][y] = max(limits[pos][y],x);
	else
		limits[pos][y] = min(limits[pos][y],x);

	if(x-1>=0)
		if(map[x-1][y] == 1 && !visited[x-1][y]) floodfill(x-1,y,map,pos);

	if(y-1 >= 0)
		if(map[x][y-1] == 1 && !visited[x][y-1]) floodfill(x,y-1,map,pos);

	if(y+1 < c)
		if(map[x][y+1] == 1 && !visited[x][y+1]) floodfill(x,y+1,map,pos);

	if(x+1 < r)
		if(map[x+1][y] == 1 && !visited[x+1][y]) floodfill(x+1,y,map,pos);
}

int calculate(int pos, int b2, vector<vector<int>> map, vector<vector<int>>& dp) {
	if(pos < 0) {
		if(b2 == 0) return b2;
		else return MAX-5;
	}

	if(dp[pos][b2] != MAX) return dp[pos][b2];

	if(b2 == 0)
		dp[pos][b2] = 0;
	else
		dp[pos][b2] = min(dp[pos][b2], min(calculate(pos-s-1,b2-1,map,dp)+limits[1][pos]-limits[0][pos]-1,calculate(pos-1,b2,map,dp)));

	return dp[pos][b2];
}

int main() {
	while(scanf("%d %d %d %d", &r,&c,&b,&s) != EOF) {
		vector<vector<int>> map(r+5);
		vector<vector<int>>dp(c+5);

		for(int i = 0; i < r; i++) {
			map[i].resize(c+5,0);
			
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
			dp[i].resize(b+5, MAX);
			limits[0][i] = 0;
			limits[1][i] = r;
		}

		floodfill(0,0,map,0);
		floodfill(r-1,0,map,1);

		//for(int i = 0; i < c; i++) printf("%d %d\n", limits[0][i]+1, limits[1][i]+1);

		int ans = calculate(c-1,b,map,dp);

		printf("%d\n", ans);

	}
	
	return 0;
}