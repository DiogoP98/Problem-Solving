#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t; 
	cin >> t;
	for(int i = 0; i < t; i++) {
		int a,b, k;
		cin >> a >> b >> k;
		long long int position = 0;
		//cout << "k=" << k/2 << endl;
		if(k%2 == 0){
			k = k/2; 
			position = (long long int)a*k - (long long int)b*k;
		}
		else {
			k = k/2;
			position = (long long int)a*(k+1) - (long long int)b*k;
		}

		cout << position << endl;
	}	
	return 0;
}