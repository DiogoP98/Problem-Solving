#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAX 350
int n;
int sqr;

vector<int>v2[MAX];

void modify(int y, int k, vector<int> v) {
    int b = y / sqr; 
   	
   	v2[b].clear();

   	for(int i = b * sqr ; i < n && i < (b+1)*sqr; i++){ 
   		v2[b].push_back(v[i]);
   	}

   	sort(v2[b].begin(),v2[b].end());
} 
  

int query(int a, int b, int x, vector<int> v) {
    int count = 0;

    while(a%sqr != 0 && a<=b) {
    	if(v[a] <= x)
    		count ++;
    	a++;
    }

    while(a+sqr <= b) {
    	count += upper_bound(v2[a/sqr].begin(), v2[a/sqr].end(), x) - v2[a/sqr].begin();
    	a+=sqr;
    }

    while(a<=b) {
    	if(v[a] <= x)
    		count ++;
    	a++;
    }
  
    return count;
} 

void build(vector<int> v) {
	int b = 0;

	for(int i = 0; i < n; i++) {
		if(i%sqr == 0 && i!= 0){ 
			sort(v2[b].begin(),v2[b].end());
			b++;
		}

		v2[b].push_back(v[i]);
	}
}

int main() {
	int q;

	scanf ("%d %d", &n, &q);

	sqr = sqrt(n);

	vector<int> v(n);

	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	build(v);

	for(int i = 0; i < q; i++) {
		char op;

		scanf(" %c", &op);

		if(op == 'M') { 
			int y, k;
			scanf("%d %d", &y, &k);
			v[y-1] = k;
			modify(y-1,k,v);
			continue;
		}

		int a,b,x;
		scanf("%d %d %d", &a, &b, &x);

		int k = query(a-1,b-1,x,v);
		printf("%d\n", k);
	}

	return 0;
}