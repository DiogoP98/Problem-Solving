/*


	Ajudas: https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/


#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int n;

void matrixChain(vector<int> m) {
	vector<vector<pair<int,int> > > v(n+5);

	for (int i=0; i<n; i++) { 
		v[i].resize(n+5);
        v[i][i].first = m[i];    } 
  
    for (int len=2; len <= n; len++) {
        for (int i=0; i<n-len+1; i++)  { 
            int j = i+len-1;
            v[i][j].second = INT_MAX; 
            for (int k=i; k<=j-1; k++) {  
            	int ini = v[i][j].second;
                v[i][j].second = min(v[i][k].second + v[k+1][j].second + v[i][k].first*v[k+1][j].first, v[i][j].second);
                if(ini != v[i][j].second) v[i][j].first = (v[i][k].first+v[k+1][j].first)%100;
            } 
        } 
    }

    printf("%d\n", v[0][n-1].second);
}

int main() {

	while(scanf("%d", &n) != EOF) {
		vector<int> m(n+5);
		for(int i = 0; i < n; i++) scanf("%d", &m[i]);

		matrixChain(m);
	}


	return 0;
}