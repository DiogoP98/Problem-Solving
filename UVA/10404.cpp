/**
	Complexidade:

	Explicação: Para cada posição na lista de pedras, vamos verificar qual é a posição que ganha. Como o stan é o primeiro, as posições
	com número igual aos números de pedras que podem ser removidas são um posição ganhadora para o stan. O resto das posições, se ao retirarmos
	qaulquer número de pedras levar a uma posição perdedora então o stan perde, caso cont´raio é também ela uma posição ganhadora.
*/


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;

void winner(vector<int> moves) {
	vector<int> dp(n+5,0);

	for(int j = 0; j < m; j++) dp[moves[j]] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < m; j++) {
			if(i-moves[j] >= 0 && dp[i-moves[j]] == 0){ 
				dp[i] = 1;
				break;
			}
		}
	}

	//if(m == 3) for(int i = 1; i <= n; i++)printf("%d ", dp[i]);
	//printf("\n");

	if(dp[n] == 1) printf("Stan wins\n");
	else printf("Ollie wins\n");
}

int main() {

	while(scanf("%d %d", &n, &m) != EOF) {
		vector<int> moves(m);
		for(int i = 0; i < m; i++) scanf("%d", &moves[i]);

		sort(moves.begin(), moves.end());

		winner(moves);
	}
	
	return 0;
}