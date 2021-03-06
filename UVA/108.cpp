/**
	Complexidade: O(n^3), n tamanho do quadrado 

	Explicação: Vamos percorrer a matriz por linhas. Para cada iteração vamos calculando a soma dos sub-retangulos 
	i a n, e guardar a soma das colunas no vector sumt. De seguida aplicamos o kadane ao vetor sumt, o que nos obtem
	a soma maxima de cada sub-retangulo. 

*/

#include <iostream>
#include <vector>
#include <climits>
#include<cstring>
#include <algorithm>

using namespace std;

int kadane(vector<int> sumt, int n) {
	int maxSum = INT_MIN, sum = 0;

	for(int i = 0; i < n; i++) {
		sum += sumt[i];
		if(sum > maxSum)
			maxSum = sum;

		if(sum < 0)
			sum = 0;
	}

	return maxSum;
}

int main() {
	int n;

	cin >> n;

	vector< vector<int> > m(n+5);

	for(int i  = 0; i < n; i++) {
		m[i].resize(n);
		for(int j = 0; j < n; j++)
			cin >> m[i][j];
	}

	vector<int> sumt(n+5);
	int max = INT_MIN;
	for(int i = 0; i < n; i++) {
		fill(sumt.begin(), sumt.end(), 0);
		for(int j = i; j < n; j++) {
			for(int k = 0; k < n; k++) sumt[k] += m[j][k];

		int sum = kadane(sumt, n);

		if(sum > max)
			max = sum;
		}
	}

	cout << max << endl;


	return 0;
}