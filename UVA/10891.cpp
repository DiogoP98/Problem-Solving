/**
	Complexidade: O(N^3)

	Explicacao: Comecamos por calcular a soma de numeros ate cada posicao e guardamos num array sum. Depois disso vamos testa
	os varios sub-intervalos á procura de uma soma maxima. Seja um sub-intervalo, [i,i+len], vamos tentar maximizar este mesmo intervalo.
	Para isso, temos que escolher o melhor intervalo, tal que, supondo que o jogador adversario vai jogar de maneira otima, consiga o menor 
	numero de pontos possivel.
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;

//vector<vector<int>> v(105);
int v[105][105];
vector<int> sum(105);

void calculate() {
	for(int len = 1; len < n; len++) {
		for(int i = 0; i + len < n; i++) {
			int s;
			if(i > 0)
				s = sum[i+len]-sum[i-1];
			else
				s = sum[i+len];

			for(int k = 1; k <= len; k++) { 
				v[i][i+len] = max(v[i][i+len], s-min(v[i+k][i+len],v[i][i+len-k]));
				v[i][i+len] = max(v[i][i+len],s);
			}
		}
	}

	cout << v[0][n-1]-(sum[n-1]-v[0][n-1]) << endl;
}

int main() {
	cin >> n;

	while(n != 0) {

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				v[i][j] = INT_MIN;
			}
		}

		for(int i = 0; i < n; i++) {
			//v[i].resize(n+5);
			cin >> sum[i];
			v[i][i] = sum[i];
			if(i!=0) sum[i] += sum[i-1];
			//cout << sum[i] << " " << v[i][i] << endl;
		}

		calculate();
		cin >> n;
	}
}