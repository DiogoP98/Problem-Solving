#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10005

vector<bool> primes(MAX,false);
vector<bool> visited(MAX);
vector<int> path(MAX);
vector<int> adj[MAX];
int n1, n2;

void generatePrimes() {
	for(int i = 2; i < 10000; i++) {
		bool has = false;
		for(int j = 2; j*j <= i; j++) {
			if(i % j == 0) {
				has = true;
				break;
			}
		}

		if(!has) primes[i] = true;
	}
}

vector<int> divideNumber(int n) {
	vector<int> number(4);

	for(int i = 0; i < 4; i++) {
		number[3-i] = n%10;
		n = n/10;
	}

	return number;
}

int buildNumber(vector<int> n) {
	int number = 0;
	
	for(int i = 0; i < 4; i++) 
		number = number*10 + n[i];

	return number;
}


void bfs() {
	queue<int> q;

	q.push(n1);

	bool found = false;

	path[n1] = 0;
	visited[n1] = true;

	while(!q.empty()) {
		int n = q.front();
		q.pop();

		if(n == n2) {
			cout << path[n] << endl;
			found = true;
			break;
		}

		vector<int> number = divideNumber(n);

		for(int i = 0; i < 4; i++) {
			vector<int> copy = number;
			for(int j = 0; j < 10; j++) {
				copy[i] = j;

				int g = buildNumber(copy);

				if(!visited[g] && primes[g] && !(i == 0 && j == 0)) {
					q.push(g);
					path[g] = path[n] + 1;
					visited[g] = true;
				}
			}
		}
	}

	if(!found) cout << "Impossible" << endl;
}

 
int main() {
	int t;
	cin >> t;

	generatePrimes();

	for(int i = 0; i < t; i++) {
		cin >> n1 >> n2;

		if(n1 == n2) cout << "0" << endl;
		else bfs();

		fill(visited.begin(), visited.end(), false);
		fill(path.begin(), path.end(), 0);
	}

	return 0;
}