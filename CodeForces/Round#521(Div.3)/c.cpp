#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n+5);
	vector<int> t(2*10e5+5,0);
	long long int sum = 0;

	for(int i = 0; i < n; i++){
		cin >> v[i];
		t[v[i]] +=1;
		sum += v[i]; 
	}

	//cout << sum << endl;
	vector<int> v2 = v;
	sort(v2.begin(),v2.end(), greater<int>());
	int count =  0;
	vector<int> num;
	for(int i = 0; i < n; i++) {
		long long int sum2 = (long long int)sum-(long long int)v[i];
		//cout << sum2 << "  i=" << i << endl;
		int l= 0, h = n-1;
		while(l <= h) {
			int m = floor(l + (h-l)/2);
			if(sum2-v2[m] > v2[m])
				h = m-1;
			else if(sum2-v2[m] < v2[m])
				l = m+1;
			else if(sum2 - v2[m] == v2[m]){
				if(v2[m] == v[i] && t[v[i]] == 1) break;
				count++;
				num.push_back(i+1);
				break;
			} 
		}
	}

	cout << count << endl;
	for(int i = 0; i < count; i++){
		if(i!= count - 1) cout << num[i] << " ";
		else cout << num[i] << endl;
	}

	return 0;
}