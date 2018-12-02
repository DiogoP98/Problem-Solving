#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
	int s;
	cin >> n >> s;
	vector<int> path(n+5);
	vector<int> pathr(n+5);

	int states;
	for(int i = 1; i <= n; i++) {
		cin >> states;
		path[i] = states;
	}

	for(int i = 1; i <= n; i++) {
		cin >> states;
		pathr[i] = states;
	}

	bool poss = false;

	if(path[1] == 0)
		printf("NO\n");
	else {
		for(int i = 1; i <= n; i++) {
			if(path[i] == 1 && pathr[i] == 1) {
				if(pathr[s] == 1 && s <=i) {
					poss = true;
					break;
				}
			}

			if(path[i] == 1) {
				if(i == s){
					poss = true;
					break;
				}
			}
		}

		if(poss)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}