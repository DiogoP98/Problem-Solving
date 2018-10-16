#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> c(n);
	vector<bool> active(n,true);

	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;

		v[i] = x;
 	}

	int n2;

	cin >> n2;

	int current = 0;
	int stillCap = v[0]; //capacidade ainda disponivel do servidor atual

	for (int i = 0; i < n2; i++) {
		string k;

		cin >> k;

		int x = 0;

		if (k == "S") {
			cin >> x;

 			if (active[x-1])
				active[x-1] = false;
			else {
				active[x-1] = true; 
				
				if (current == x-1)
					stillCap = v[current];
			}
		}

		else {
			for(int j = 0; j < k.size(); j++) {
				x = (int)(k[j]-'0')+ x*10;
			}


			while(x>0) {

				if (stillCap == 0) {
					current = (current+1)%n;
					stillCap = v[current];
				}

				while (!active[current]) {
					current = (current+1)%n;
					stillCap = v[current];
				}

				x -= stillCap;

				if(x < 0) {
					stillCap = abs((int)x);
					c[current] += v[current] - stillCap;
				}
				else if (x==0) {
					stillCap= 0;
					c[current] += v[current];
				}
				else {
					c[current] += stillCap;
					current = (current+1)%n;
					stillCap = v[current]; 
				}
 
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << c[i] << endl;
	}

	return 0;
}