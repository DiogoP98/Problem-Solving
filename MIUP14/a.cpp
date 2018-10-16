#include <iostream>
#include <climits>
#include <cfloat>
#include <string>
#include <math.h>
#include <stdlib.h>


using namespace std;

int main() {
	char c;

	cin >> c;

	int x, y,n;

	cin >> x >> y;

	cin >> n;

	double min = DBL_MAX;
	int minID = INT_MAX;
	for (int i = 0; i <n; i++) {
		int id, xx, yy;
		string t;

		cin >> id >> xx >> yy >> t;

		if (t.find(c) != string::npos) {
			if (c == 'H' || c=='P') {
				int dx = x-xx;
				int dy = y-yy;

				dx = dx*dx;
				dy = dy*dy;

				double d = sqrt(dx+dy);

				if (d < min) {
					min = d;
					minID = id;
				}
				else if (d == min) {
					if (id < minID)
						minID = id;
				}
			}
			else {
				int dx = abs(x-xx);
				int dy = abs(y-yy);

				double d = dx+dy;

				if (d < min) {
						min = d;
						minID = id;
					}
				else if (d == min) {
					if (id < minID)
						minID = id;
				}
			}
		}
	}

	cout << minID << endl;
	
	
}