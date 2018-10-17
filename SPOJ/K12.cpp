/**
	O(m * nlogn) - m- numero de casos, n tamanho da sequencia.
	Como pesquina ternaria tem complexidade O(logn) e em cada ciclo da pesquisa percorremos o vetor h e c, que têm
	tamanho n, a complexidade total da pesquina ternaria vai ficar O(nlogn). Isto para m casos teste.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;

		cin >> n;

		vector<int> h(n);
		vector<int> c(n);

		int min = 15000, max = -1;

		for(int j = 0; j < n; j++) {
			cin >> h[j];

			if (h[j] > max)
				max = h[j];

			if (h[j] < min)
				min = h[j];
		}

		for(int j = 0; j < n; j++) {
			cin >> c[j];
		}

		long long int sum1, sum2;
		while(max > min) {

			int m1 = min + (max-min) / 3;
			int m2 = max - (max-min) / 3;

			//cout << max << " " << min << endl;
			sum1 = 0;
			sum2 = 0;

			for(int j = 0; j < n; j++) {
				sum1 += (long long int) abs(h[j]-m1) * c[j];
				sum2 += (long long int) abs(h[j]-m2) * c[j];
			}

			//cout << sum1 << " " << sum2 << endl;

			if(sum1 > sum2)
				min = m1+1;
			else
				max = m2-1;

		}

		sum1=0;

		for (int j = 0; j < n; j++)
			sum1 += (long long int) abs(h[j]-min) * c[j];

		cout << sum1 << endl;
	} 

	return 0;
}