#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define MAX 10005
#define EPS 1e-6

struct point {
	double x;
	double y;
};

struct line {
	point p1;
	point p2;

	/*
	double a;
	double b; 
	double c;
	*/
};

vector<point> vertexes(MAX);
double thresh, xbird;
int n;
line bird;

bool compare (point &a, point &b) {
    return a.y < b.y;
}

/*
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
		l.a = 1.0; 
		l.b = 0.0; 
		l.c = -p1.x; 
	} 
	else {
		l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0; 
	}
}

bool areParallel(line l1, line l2) { // check coefficients a & b 
	return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2)) 
		return false;
	
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

	if (fabs(l1.b) > EPS) 
		p.y = -(l1.a * p.x + l1.c); 
	else 
		p.y = -(l2.a * p.x + l2.c); 

	return true; 
}
*/


bool intersection(line l, point& r) {
	double a1 = l.p2.y - l.p1.y; 
    double b1 = l.p1.x - l.p2.x; 
    double c1 = a1*(l.p1.x) + b1*(l.p1.y); 
  
    double a2 = bird.p2.y - bird.p1.y; 
    double b2 = bird.p1.x - bird.p2.x; 
    double c2 = a2*(bird.p1.x)+ b2*(bird.p1.y); 
  
    double determinant = a1*b2 - a2*b1; 
  
    if (determinant == 0) 
 		return false;

    else { 
        r.x = (b2*c1 - b1*c2)/determinant; 
        r.y = (a1*c2 - a2*c1)/determinant; 
        return true; 
    }
 }  

double dist(point p1, point p2) {
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy); 
}

bool calculate() {
	int count = 0, j = n - 1;
	double sum = 0;
	

	line l;

	vector<point> intersections;
	point intersect;

	for(int i = 0; i < n; i++) {
		l.p1 = vertexes[j];
		l.p2 = vertexes[i];

		//pointsToLine(vertexes[j],vertexes[i], l);

		if((vertexes[j].x >= xbird && vertexes[i].x >= xbird) || (vertexes[j].x <= xbird && vertexes[i].x <= xbird)) {
			j = i;
			continue;
		}

		if(intersection(l, intersect)) {
			/*
			count++;

			if(count % 2 == 0) {
				double d = dist(intersect,intersectp);
				sum += d;
			}

			else
				intersectp = intersect;
			*/
			intersections.push_back(intersect);
		}

		j = i;
	}

	sort(intersections.begin(), intersections.end(), compare);

	for(int i = 0; i < intersections.size(); i += 2) 
		sum += dist(intersections[i],intersections[i + 1]);

	if(sum + EPS > thresh)
		return true;
	else
		return false;
}

int main() {
	int t;
	cin >> t;
	double maxy;

	for(int i = 0; i < t; i++) {
		cin >> n;
		maxy = 0;

		for(int j = 0; j < n; j++) {
			cin >> vertexes[j].x >> vertexes[j].y;
			maxy = max(maxy,vertexes[j].y);
		}

		cin >> thresh >> xbird;

		
		bird.p1.x = bird.p2.x = xbird;
		bird.p1.y = 0;
		bird.p2.y = maxy + 5;

		/*
		point p1, p2;
		p1.x = p2.x = xbird;
		p1.y = 0;
		p2.y = maxy + 5;

		pointsToLine(p1,p2,bird);
		*/	

		if(calculate())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		point reset;
		reset.x = 0, reset.y = 0;

		fill(vertexes.begin(), vertexes.end(), reset);
	}	
}