/*
	
	Ajudas: http://www.mathcs.emory.edu/~cheung/Courses/170/Syllabus/07/bisection.html
*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

vector<int> values(6);

double calculate(double x) {
	return values[0] * exp(-x) + values[1] * sin(x) + values[2] * cos(x) + values[3] * tan(x) + values[4] * (x*x) + values[5];
}

double bisection() {
	double a, b ,c;
	bool pa, pb; //false se o valor for negativo, true caso contrario

	a = 0.0; 
	b= 1.0;

	double va = calculate(a);
	double vb = calculate(b);

	if (va * vb > 0) {
		cout << "No solution" << endl;
		return -10.0;
	}

	for(int  i = 0; i < 50; i++){
		c = (a+b)/2;

		double value = calculate(c);

		if (value * va <= 0)
			b = c;
		else
			a = c;
	}

	return c;

}

int main() {
	double c;

	while(scanf("%d %d %d %d %d %d", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5]) == 6) {
		c = bisection();

		if(c != -10.0)
			printf ("%.4lf\n", c);

	}
	
	return 0;
}