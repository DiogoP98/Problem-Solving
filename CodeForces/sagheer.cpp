/*
	Complexidade: O(n * (logn)^2), n e o numero de items.
	
	Fazemos pesquisa binária sobre o número de items. Para cada valor intermédio obtido vamos
	verificar qual é o total. Para tal, guardamos os valores intermédios num vetor u e ordenamos este
	vetor por ordem crescente de maneira a obter o menor valor possivel pelos m items. Depois é só verificar
	se a soma é maior ou menor do que o valor que ele pode gastar e se for maior, significa que tem que comprar
	menos items, e por isso o limite superior vai ser o m - 1 (de maneira a convergir), caso contrário o limite inferior é o m.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,s;

	cin >> n >> s;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int l = 0, h = n;

	long long int max = 0, min = 0;

	while(l < h) {
		int m = l + (h-l+1)/2;

		vector<long long int> u(n);
		long long int sum = 0;

		for (int i = 0; i < n; i++) 
			u[i] = (long long int) v[i] + (long long int)(i+1) * m;

		sort(u.begin(),u.end());

		for (int i = 0; i < m; i++)
			sum += u[i];

		if(sum <= s){
			l = m;
			min = sum;
			max = m;
		}
		else
			h = m -1;
	}

	cout << max << " " << min << endl;

	return 0;
}