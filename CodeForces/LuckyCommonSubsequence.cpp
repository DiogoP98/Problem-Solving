/**
	Complexidade: O(n*m*k), sendo n e o tamanho das strings e k o tamanho da string virus,
	
	Explicacao: E construido um array, usando a failure function do KMP, sobre a string virus. 
	Para resolver a subsequencia maior, usamos uma estrutura tipica desses problemas, adicionanado apenas
	um array para o virus. Assim, a unica coisa que muda, é quando sao encontradas letras iguais, verificar
	em que parte da string virus o algoritmo esta.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

#define MAX 105

vector<int> f(MAX);
int lcs[MAX][MAX][MAX];
string lcsstring[MAX][MAX][MAX];
string s1, s2,virus;
int n1, n2, nvirus;

void failure() {
	int j = -1;
	f[0] = -1;

	for(int i = 1; i < nvirus; i++) {
		while(j > -1 && virus[j+1] != virus[i]) j = f[j];

		if(virus[j+1] == virus[i]) j++;

		f[i] = j;
	}
}

int KMP(int k, int i) {
	while(k >= 0 && virus[k+1] != s1[i]) k = f[k];

	if(virus[k+1] == s1[i])  k++;

	return k;
}

int lucky(int i, int j, int k) {
	if(i == n1 || j == n2) return lcs[i][j][k] = 0;

	if(lcs[i][j][k] != -1) return lcs[i][j][k];

	lcs[i][j][k] = 0;
	
	if(lucky(i,j+1,k) > lucky(i+1,j,k)) {
		lcs[i][j][k] = lcs[i][j+1][k];
		lcsstring[i][j][k] = lcsstring[i][j+1][k];
	}
	else {
		lcs[i][j][k] = lcs[i+1][j][k];
		lcsstring[i][j][k] = lcsstring[i+1][j][k];
	}
	
	if(s1[i] == s2[j]) {
		int m = KMP(k-1,i);
		if(m != nvirus - 1) {	
			if(lucky(i+1,j+1,m+1) + 1 > lcs[i][j][k]) {
				lcs[i][j][k] =  lcs[i+1][j+1][m+1] + 1; 
				lcsstring[i][j][k] = lcsstring[i+1][j+1][m+1] + s1[i];
			}
		}
	}
		
	return lcs[i][j][k];
}

int main() {
	cin >> s1 >> s2 >> virus;
	n1 = s1.length();
	n2 = s2.length();
	nvirus = virus.length();

	memset(lcs,-1,sizeof lcs);

	failure();

	int ans = lucky(0,0,0);

	if(ans == 0) cout << ans << endl;
	else{ 
		reverse(lcsstring[0][0][0].rbegin(),lcsstring[0][0][0].rend());
		cout << lcsstring[0][0][0] << endl;
	}

	return 0;
}