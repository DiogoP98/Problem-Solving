#include <iostream>
#include <vector>

using namespace std;

int n;

int query(int l, vector<long long int> lengths) {
	int time = 0;
	if(lengths[0] > l)
		time = 1;
	for(int i = 1; i < n; i++) {
		if(lengths[i] > l && lengths[i-1] <= l) time += 1;
	}

	return time;
}

int main() {
	int m, l;
	cin >> n >> m >> l;

	vector<long long int> lengths(n+5,0);
	for(int i = 0; i < n; i++) cin >> lengths[i];

	int time = query(l, lengths);
	int op;
	for(int i = 0; i < m; i++) {
		cin >> op;
		if(op == 0) printf("%d\n", time);
		else {
			int p, cl;
			cin >> p >> cl;
			p--;
			if(lengths[p] <= l && cl+lengths[p] > l){
				if(p+1 < n && p-1 >=0) {
					if(lengths[p-1] <= l && lengths[p+1] <= l) time +=1;					
					else if(lengths[p-1] > l && lengths[p+1] > l) time-=1;
				}
				else if(p-1 <0) {
					if(lengths[p+1] <= l) time +=1;
				}
				else if(p+1 >= n){
					if(lengths[p-1] <= l) time +=1;
				}
				else time+=1;
			}
			lengths[p] += (long long int)cl;
		}
	}
	
	return 0;
}