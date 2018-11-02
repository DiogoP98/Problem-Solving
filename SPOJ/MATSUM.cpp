/**
	Complexidade: O((nm+q)*log(nm)), q numbero de queries, n a coordenada x maxima no update e m a 
	coordenada y.

*/


#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 1030

int bit2d[MAX][MAX];
int matrix[MAX][MAX];
int n;

void buildBit() {

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			bit2d[i][j] = 0;
			matrix[i][j] = 0;
		}
	}

}

void update(int x, int y, int num) {
	int yval = y;
	while(x <= n) {
		y = yval;
		while(y <= n) {
			bit2d[x][y] += num;
			y += y & (-y);
		}

		x += x & (-x);
	}
}

int sum(int x, int y) {
	int sum = 0;
	int yval = y;
	while(x > 0) {
		y = yval;
		while(y > 0) {
			sum += bit2d[x][y];

			y -= y & (-y);
		}

		x -= x & (-x);
	}

	return sum;
}

int main() {
	int t;
	scanf("%d", &t);

	for(int i = 0; i < t; i++) {
		scanf("%d", &n);
		buildBit();

		char op[5];

		while(true) {
			scanf("%s", op);
			if (strcmp(op,"END") == 0) break;
			else if (strcmp(op,"SET") == 0) {
				int x, y, num;
				scanf("%d %d %d", &x, &y, &num);
				x++, y++;
				update(x,y, -matrix[x][y] + num);
				matrix[x][y] = num;
			}
			else {
				int x1, y1, x2, y2;
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1+=1; y1+=1; x2+=1; y2+=1;
				//printf("%d %d %d %d\n", sum(x2,y2), sum(x2,y1-1), sum(x1-1,y2), sum(x1-1, y1-1));
				int ans = sum(x2,y2) - sum(x2,y1-1) - sum(x1-1,y2) + sum(x1-1, y1-1); 
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}