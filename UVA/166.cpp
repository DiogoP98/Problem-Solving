/*
	Complexidade: O(s * q), onde s e a quantidade de dinheiro possivel e q a quantidade de cada moeda. 

	Explicacao: Para cada valor, vamos percorrer a quantidade total de dinheiro possivel, e o numero possivel de vezes que podemos usar o mesmo. 
	Se a quantidade de dinheiro que formamos, com k vezes o valor, for menor ou igual á quantidade total de dinheiro, então o numero de moedas, 
	vai ser k + o numero de moedas que precisamos para o valor restante.
	Depois de completar a matriz, vamos percorrer, os valores entre o valor do pagamento e a quantidade de dinheiro possivel, e a resposta
	vai ser o numero de moedas que conseguimos obter, usando uma certa quantidade, mais o numero de moedas do troco, se usarmos essa qunatidade.
*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

#define MAX 1000

int n, sum;
vector<int> coins = {5,10,20,50,100,200};
vector<int> q(10);

int calculate2(int value) {
	vector<int> cal2(value+5, MAX);
	cal2[0] = 0;
	for(int i = 1; i <= value; i++) {
		for(int j = 0; j < 6; j++) {
			if(coins[j] <= i) cal2[i] = min(cal2[i], cal2[i-coins[j]] + 1); 
		}
	}
	return cal2[value];
}

void calculate() {
	vector<int> cal(sum+5,MAX);
	vector<vector<int>> used(n+5,vector<int>(10));

	cal[0] = 0;

	for(int i = 0; i < 6; i++) {
		for(int j = sum; j >= 0; j--) {
			for(int k = 1; k <= q[i]; k++) {
				if(coins[i] * k <= j) cal[j] = min(cal[j-coins[i]*k] + k , cal[j]);
			}
		}
	}

	int ans = MAX;

	for(int i = n; i <= sum; i++) ans = min(ans, cal[i]+calculate2(i-n));

	printf("%3d\n", ans);
}

int main() {
	int v1, v2;

	scanf("%d %d %d %d %d %d", &q[0], &q[1], &q[2], &q[3], &q[4], &q[5]);

	while(scanf("%d.%d", &v1, &v2) != EOF) {
		sum = 0;
		n = v1*100+v2;
		for(int i = 0; i < 6; i++) {
			sum += coins[i]*q[i];
		}
		calculate();
		scanf("%d %d %d %d %d %d", &q[0], &q[1], &q[2], &q[3], &q[4], &q[5]);
	}

	return 0;
}