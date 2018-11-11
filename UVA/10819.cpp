#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF) {
		int orim = m;
		
		if(m > 1800)
			m += 200;

		vector<int> v(m+5,0);
		vector<pair<int,int>> items(n+5);

		for(int i = 1; i <= n; i++) {
			int size, val;
			scanf("%d %d" ,&size, &val);
			items[i] = make_pair(size,val);
		}

		for(int i= 1; i <= n; i++) {
			for(int j = m; j >= items[i].first; j--) {
				if(v[j - items[i].first] > 0 || j == items[i].first) v[j] = max(v[j], v[j-items[i].first] + items[i].second);
	 		}
		}

		int ans = 0;
   		 for (int i = 1; i <= m; i++) {
   		 	if (orim > 2000 || i < orim || i > 2000) ans = max(ans, v[i]);
    	}

    	printf("%d\n", ans);
	}

	return 0;
}