/**
	Ajudas: https://www.geeksforgeeks.org/strongly-connected-components/

	complexidade temporal: O(V+E), correspondente á complexidade do DFS.

	Explicacao: Executamos um algoritmo de maneira a ter as componentes fortemente conexas.

*/


#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#define MAX 1005

map<string, int> varmap;
int nnames;
vector<int> trust[MAX];
vector<int> trustinv[MAX];
vector<bool> visited(MAX, false);
int ncomponents;


void reset() {
	for(int i = 0; i < nnames; i++) {
		trust[i].clear();
		trustinv[i].clear();
	}
	fill(visited.begin(), visited.end(), false);
	varmap.erase(varmap.begin(), varmap.end());
}

string readname() {
	string np, s;
	cin >> s >> np;
	string n = np + s;
	return n;
}

void buildStack(int v, vector<bool>& visited, stack<int>& s) {
	visited[v] = true;

	for(int i = 0; i < (int) trust[v].size(); i++) {
		if(!visited[trust[v][i]])
			buildStack(trust[v][i], visited, s);
	}

	s.push(v);
}

void dfs(int v, vector<bool>& visited) {
	visited[v] = true;

	for(int i = 0; i < (int) trustinv[v].size(); i++) {
		if(!visited[trustinv[v][i]])
			dfs(trustinv[v][i], visited);
	}
}

void components() {
	stack<int> s;

	for(int i = 0; i < nnames; i++) {
		if(!visited[i]) {
			buildStack(i, visited, s);
		}
	}

	fill(visited.begin(), visited.end(), false);

	while(!s.empty()) {
		int v = s.top();
		s.pop();

		if(!visited[v]) {
			ncomponents++;
			dfs(v,visited);
		}
	}
}

int main() {
	int p, t;
	cin >> p >> t;

	while(p != 0 || t != 0) {
		nnames = 0;
		ncomponents = 0;
		for(int i = 0; i < p; i++){
			string n = readname();
			varmap.insert(make_pair(n,nnames));
			nnames++;
		}

		for(int i=0; i < t; i++) {
			string n = readname();
			auto it = varmap.find(n);
			string n2 = readname();
			auto it2 = varmap.find(n2);

			trust[it->second].push_back(it2->second);
			trustinv[it2->second].push_back(it->second);
		}

		components();

		cout << ncomponents << endl;
		reset();
		cin >> p >> t;
	}	
}