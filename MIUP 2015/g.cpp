#include <iostream>
#include <vector>

using namespace std;

int main() {	
	int n,r,c;

	cin >> n >> r >> c;

	vector < pair<int,int> > adj[r];

	for (int i = 0; i < c; i++) {
		int r1, r2, v;
		char t;

		cin >> r1 >> r2 >> t >> v;


		if (t == 'B')
			adj[r1].push_back(make_pair(r2, v));
		else
			adj[r1].push_back(make_pair(r2, -v));

	}


	return 0;
}