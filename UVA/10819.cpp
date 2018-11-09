#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int m, n;
	while(scanf("%d %d", &m, &n) != EOF) {
		int ori = m;
		if(m > 1800)
			m += 200;

		vector<int> v(m+5);
		vector<pair<int,int>> items(n+5);

		for(int i = 0; i <= m; i++) v[i] = 0;

		for(int i = 1; i <= n; i++) {
			int size, val;
			scanf("%d %d" ,&size, &val);
			items[i] = make_pair(size,val);
		}

		for(int i= 1; i <= n; i++) {
			for(int j = m; j >= 0; j--) {
				if(items[i].first <= j) v[j] = max(v[j], v[j-items[i].first] + items[i].second);
	 		}
		}

		int ans = 0;
	    if (ori > 1800 && ori <= 2000) {
	      for (int i = 0; i < ori; i++)
	        ans = max(ans, v[i]);
	      for (int i = 2001; i <= m; i++)
	        ans = max(ans, v[i]);
	    } else {
	      for (int i = 0; i <= m; i++)
	        ans = max(ans, v[i]);
	    }

		printf("%d\n", ans);
	}

	return 0;
}