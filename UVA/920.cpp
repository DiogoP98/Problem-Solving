/*
	Complexidade: O(n), sendo n o numero de pontos.

	Explicacao: Vamos percorrer o vetor de pontos, e para cada ponto, se a altura for maior do que altura maxima ate entao, significa que o sol
	vai la bater, logo e so calcular a parte da montanha que vai apanhar sol. Fazemos isto para todos os pontos.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX 105

struct point{
	int x;
	int y;
};

vector<point> points;
int n;

bool compare (point &a, point &b) {
    return a.x < b.x;
}

double euclidean(point p1, point p2) {
	double dx = p1.x-p2.x;
	double dy = p1.y-p2.y;
	return sqrt(dx*dx + dy*dy);
}

void calculate() {
	int maxy = 0;
	double ans = 0;

	for(int i = n-2; i >= 0; i--) {
		if(points[i].y > maxy) {
			double eucl = euclidean(points[i], points[i+1]);
			double dy = points[i].y-points[i+1].y;
			double diff = points[i].y - maxy;
			ans += eucl * diff / dy;
			maxy = points[i].y;
		}
	}

	printf("%.2f\n", ans);
}

int main() {
	int c;

	cin >> c;

	for(int i = 0; i < c; i++) {
		cin >> n;

		for(int j = 0; j < n; j++) {
			point p;
			cin >> p.x >> p.y;
			points.push_back(p);
		}

		sort(points.begin(), points.end(), compare);

		/*
		for(int j = 0; j < n; j++) {
			cout << points[j].x << "   " << points[j].y << endl;
		}
		*/

		calculate();

		points.clear();	
 	}
}