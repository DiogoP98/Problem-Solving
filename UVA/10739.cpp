/**
	Complexidade: O(n^2).

	Explicacao: De maneira a encontrar o numero minimo de operacoes, vamos construir uma matriz parecida com a de longest commom
	subsequence. No entanto, cada vez que encontramos uma letra igual, significa que nao e preciso fazer nenhuma alteracao. Em cada posicao
	da matriz, vai estar o numero minimo de alteracoes, e quando estamos numa certa posicao, o valor da mesam vai ser o minimo entre:
	o numero de operacoes necessarias ate á letra anterior + 1 caso sejam diferentes, ou igual ao mesmo se forem iguais e o numero de operacoes
	da string anterior mais 1.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int t;

	cin >> t;

	for(int i = 0; i < t; i++) {
		string s;
		cin >> s;

		int size = s.length();

		string s2 = s;

		reverse(s2.begin(), s2.end());

		vector<vector<int> > v(size+5);

		for(int j = 0; j <= size; j++) { 
			v[j].resize(size+5);
			v[j][0] = j;
		}

		for(int j = 0; j <= size; j++) v[0][j] = j;

		for(int j = 1; j <= size; j++) {
			for(int k = 1; k <= size; k++) {
				int value;
				if(s[j-1] == s2[k-1])  value = 0;
				else value = 1;
				v[j][k] = min(v[j-1][k-1] + value, min(v[j-1][k]+1,v[j][k-1]+1));
			}
		}

		cout << "Case " << i+1 << ": " << v[size][size]/2 << endl;

	}
	return 0;
}