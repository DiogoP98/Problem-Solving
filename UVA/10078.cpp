/*
	Complexidade: O(n), sendo n o numero de vertices

	Explicacao: Tendo os vertices num array vamos verificar se todos estao virados para o mesmo
	sentido, ou seja, se formam um poligono convexo. Fazemos isso através do ccw, que recebendo 3
	pontos e capaz de retornar o tipo de angulo entre eles.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point {
	int x;
	int y;
};

struct vec { 
	double x;
	double y;
};

#define MAX 55

vector<point> points;
int n;

bool compare (point &a, point &b) {
    return a.x < b.x;
}

vec toVec(point a, point b) {
	vec v;
	v.x = b.x - a.x;
	v.y = b.y - a.y;
	return v; 
}

bool ccw(point p, point q, point r) {
	vec pq = toVec(p, q);
	vec pr = toVec(p, r);

	double res = pq.x * pr.y - pq.y * pr.x;

	return res > 0;
}

bool isConvex() { 
	if (n < 3) return false;

	bool isLeft = ccw(points[0], points[1], points[2]);

	for (int i = 1; i < n ; i++){
		if (ccw(points[i], points[i+1], points[i+2]) != isLeft)
			return false;
	}
	
	return true; 
}

int main() {
	cin >> n;

	while(n != 0) {

		for(int i = 0; i < n; i++) {
			point p;
			cin >> p.x >> p.y;
			points.push_back(p);
		}

		points.push_back(points[0]);
		points.push_back(points[1]);

		if(isConvex())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;

		cin >> n;

		points.erase(points.begin(), points.end());
	}

	return 0;
}