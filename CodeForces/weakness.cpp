#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n);
	double l = 15000, h = -15000;

	for (int i = 0; i < n; i++) {
		cin >> v[i];

		if(v[i] < l)
			l = v[i];
		
		if(v[i] > h)
			h = v[i];
	}

	double m1,m2;
	double maxg, max2g;
	
	for(int j= 0; j < 100; j++) {
		double m1 = l + (h-l) / 3;
		double m2 = h - (h-l) / 3;

		vector<double> v2(n);
		vector<double> v3(n);
		for(int i = 0; i < n; i++) {
			v2[i] = v[i] - m1;
			v3[i] = v[i] - m2;
		}

		double maxp= 0, max2p= 0, count = 0, count2 = 0; 
		for(int i = 0; i < n; i++) { //encontrar poorness maxima entre valores positivos
			count += v2[i];
			count2 += v3[i];

			v2[i] *= -1;
			v3[i] *= -1;

			if(count > maxp)
				maxp = count;
			
			if(count< 0)
				count = 0;

			if(count2 > max2p)
				max2p = count2;

			if(count2< 0)
				count2 = 0;
		}

		count = 0, count2 = 0;
		double maxn = 0, max2n = 0;

		for(int i = 0; i < n; i++) { //encontrar poorness máxima entre os valores negativos
			count += v2[i];
			count2 += v3[i];

			if(count > maxn)
				maxn = count;
			
			if(count< 0)
				count = 0;

			if(count2 > max2n)
				max2n = count2;

			if(count2< 0)
				count2 = 0;

		}

		maxg = max(maxn,maxp);
		max2g = max(max2n, max2p);

		//cout << "here: " << maxg << " " << max2g << endl;
		if (maxg > max2g)
			l = m1;
		else
			h = m2;
	}
	printf("%.16f\n",maxg);

	return 0;
}
