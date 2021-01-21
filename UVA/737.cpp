/*
	Complexidade: O(n), sendo n o numero de cubos.

	Explicacao: Usamos o primeiro cubo como referência, e depois vamos percorrer todos os outros cubos, para ver se alguma parte deles, esta contida
	no cubo de referencia. Se estiver, atualizamos o cubo de referencia. No final basta calcular a sua area.

*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX  1005

struct cube {
	int x;
	int y;
	int z;
	int rx;
	int ry;
	int rz;
};

vector<cube> c(MAX);
int n;

bool checkInterception(cube& ref, cube p) {
	if(ref.x > p.rx || ref.y > p.ry || ref.z > p.rz) return false;

	if(p.x > ref.rx || p.y > ref.ry || p.z > ref.rz) return false;

	ref.x = max(ref.x,p.x);
	ref.y = max(ref.y,p.y);
	ref.z = max(ref.z,p.z);
	ref.rx = min(ref.rx,p.rx);
	ref.ry = min(ref.ry,p.ry);
	ref.rz = min(ref.rz,p.rz);

	return true;
}

void calculate() {
	cube ref = c[0];
	for(int i = 1; i < n; i++) {
		if(!checkInterception(ref,c[i])) {
			cout << "0" << endl;
			return;
		}
	}

	long long int res = (ref.rx-ref.x)*(ref.ry-ref.y)*(ref.rz-ref.z);

	cout << res << endl;	
}

int main() {
	cin >> n;

	while(n != 0) {
		int r;

		for(int i = 0; i < n; i++) {
			cube t;
			cin >> t.x >> t.y >> t.z >> r;

			t.rx = t.x + r;
			t.ry = t.y + r;
			t.rz = t.z + r;
			c[i] = t; 
		}

		calculate();

		cin >> n;		
	}
}