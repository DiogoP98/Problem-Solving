#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;


int n;
int n2;

void checkMax(vector<int> v, int pos, vector<int>& maxOrder, vector<int>& seq) {
	for (int i = pos+1; i < n2; i++) {
		if (v[i] > v[pos]) {
			if (maxOrder[i] + 1 > maxOrder[pos]) {
				maxOrder[pos] = maxOrder[i] + 1;
				seq[pos] = i;
			}
		}
	}
	if (pos-1 >= 0)
		checkMax(v,pos-1,maxOrder,seq);
}

int main() {
	cin >> n;
	char x[10];

	cin.getline(x,10);
	cin.getline(x,10);

	for (int i = 0; i < n; i++) {
		if (i != 0)
			cout << endl;
		vector<int> ar(1000);
		n2 = 0;
		cin.getline(x,10);
		while(strcmp(x,"") != 0 && strcmp(x,"\n") != 0) {
			int v = atoi(x);
			ar[n2] = v;
			n2++;
			cin.getline(x,10);
		}
		vector<int> maxOrder(n2,1);
		vector<int> seq(n2,0);
		checkMax(ar,n2-1,maxOrder,seq);
		int max = 0;
		int maxp = 0;
		for (int j = 0; j < n2; j++) {
			if (maxOrder[j] > max) {
				max = maxOrder[j];
				maxp = j;
			}
		}
		cout << "Max hits: " << max << endl;
		cout << ar[maxp] << endl;
		while (seq[maxp] != 0) {
			maxp = seq[maxp];
			cout << ar[maxp] << endl;
		}
	}

	
	return 0;
}