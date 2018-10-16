#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int> adj[], vector<int>& prec, vector<bool>& visited, int n, int h) {
	queue<int> q;
	vector<int> w(n,0);
	for (int i = 0; i < n; i++) {
		if (prec[i] == 0)
			q.push(i);
	}

	int max = 0;
	int cweek = 0;
	int perweek = 0;
	int hweeks = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();


		if (w[x] != cweek) { 
			cweek = w[x];
			if (perweek > max)
				max = perweek;
			if (perweek > h)
				hweeks++;
			perweek = 1;
		}
		else
			perweek++;

		for (int i = 0; i < (int) adj[x].size(); i++) {
			int node = adj[x][i];
			prec[node]--;

			if (prec[node] == 0) {
				q.push(node);
				w[node] = cweek+1;
			}
		}
	}

	if (perweek > h)
		hweeks++;
	if (perweek > max)
		max = perweek;

	cout << max << " " << hweeks << endl;	

}


int main() {
	int n, n2, h;
	cin >> n >> n2 >> h;

	vector<int> adj[n];
	vector<int> prec(n,0);
	vector<bool> visited(n,false);

	for (int i = 0; i < n2; i++) {
		int e1, e2;
		cin >> e1 >> e2;
		adj[e1].push_back(e2);
		prec[e2]++;
	}

	bfs(adj,prec,visited,n,h);

	return 0;
}