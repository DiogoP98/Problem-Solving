#include <cstdio>
#include <vector>

using namespace std;

int r,c;

int main() {
	
	while(scanf("%d %d", &r, &c) != EOF) {
		vector<vector<int>> map(r+5);

		for(int i = 0; i < r; i++) {
			map[i].resize(c+5);
			for(int j = 0; j < c; j++) {
				char type;
				scanf("%c", &type);
				if(type == '#') map[i][j] = 1;
				else map[i][j] = 0;
			}
		}
	}

	return 0;
}