/*
	Complexidade: O(nlog(n)), onde n e o numero de estabulos

	Começamos por ordenar os estabulos por ordem crescente de maneira a ser mais facil calcular as distancias entre
	os estabulos. De seguida, fazemos pesquisa binaria sobre a distancia. Para cada valor m calculamos o numero de vacas
	que e possivel ter segundo as restricoes e se for maior ou igual que o numero de vacas pedido entao significa que 
	podemos conseguir ter ainda uma maior distancia minima e por isso aumentamos o lower bound para m. Caso contrario
	significa que a distancia tem que ser menor. 

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n,s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, c;

		cin >> s >> c;

		vector<int> v(5000000);

		for (int i = 0; i < s; i++) {
			cin >> v[i];
		}

		sort(v.begin(), v.begin()+s);

		int l = 0, h = pow(10,9);

		int mm;

		while(l < h) {
			int m = l + (h-l+1)/2;

			
			int fs = v[0];
			int ncows = 1;

			for (int j = 1; j < s; j++) {
				if(v[j] - fs >= m) {
					ncows++;
					fs = v[j];
				}
			}

			if(ncows >= c){
				mm = m;
				l = m;
			}

			else
				h = m - 1;
		}

		cout << mm << endl;
	}

	return 0;
}