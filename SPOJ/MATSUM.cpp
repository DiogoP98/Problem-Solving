/**
	Ajudas: https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/

	Complexidade: O((nm+q)*log(nm)), q numbero de queries, n a coordenada x maxima no update e m a 
	coordenada y.

	Explicacao: Cada nó da BIT é também outra BIT. Ao fazermos update, a BIT é atualizada de (x,y) até (n,n).
	Para a operação query, é nos dado um sub-retângulo da matriz, e como cada vez que a funcao sum é chamada, 
	a soma vai ser de todos os valores entre (x,y) e (0,0), para obtermos a soma certa precisamos da seguinte formula:
	sum(x2,y2) - sum(x2,y1-1) - sum(x1-1,y2) + sum(x1-1, y1-1). Como dito antes o sum(x2,y2), que representa o canto
	superior direito do sub-retângulo vai obter a soma entre (x2,y2) e (0,0), no entanto se o canto inferior esquerdo
	for maior do que isso estamos a obter uma soma maior do que aquela que queremos. Logo a sum(x2,y2) precisamos de remover
	a sum(x2,y1-1) e a sum(x1-1,y2). No entanto, ao subtrair estas duas estamos a subtrair duas vezes o espaço
	(x-1,y-1), (0,0), e por isso temos que somar esse valor ao resultado obtido. 

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