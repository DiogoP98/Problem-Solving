/**
	Complexidade: O(n+e), sendo n o numero de letras e "e" o numero de ligacoes entre as letras.

	Explicacao: Paraca cada uma das variaveis iniciais que nao dependem de outras, fazemos um topological sort, e cada vez que chegarmos a posicao
	final, isto e, que todos os nós já estiverem escolhidos imprimimos a sequencia. O topological sort, e feito de froma recursiva para 
	cada no escolhido, ou seja, cada no que já nao estiver dependente de outros.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 25
#define MAXO 300

int nvar;
vector<int> adj[MAX];
map<char,int> varmap;
vector<int> parents(MAX); 
vector<bool> visited(MAX);
vector<char> variables;
bool solution;


void printfDebug() {
	/*
	for(int j = 0; j < available.size(); j++) {
		cout << "here=" << available[j] << endl;
	}

		
	for(auto j = varmap.begin(); j != varmap.end(); j++) {
		cout << "var=" << j->first << " " << j-> second << endl;
		cout << parents[j->second] << endl;
		cout << "----------" << endl;
	}

	cout << "visited:" << endl;
	for(int i = 0; i < nvar; i++) cout << visited[i] << " ";
	cout << endl;
	cout << "--------" << endl;
	

	for(int i = 0; i < nvar; i++) cout << variables[i] << endl;
	*/
}

void clearar() {
	variables.clear();
	fill(parents.begin(), parents.end(), 0);
	for(int i = 0; i < MAX; i++)
		adj[i].clear();
	varmap.erase(varmap.begin(), varmap.end());
}

char returnValueInMap(int x) {
	auto it = varmap.begin();
	for(int i = 0; i < x; i++){
		it++;
	}
	char c = it->first;
	return c;
}

void findAvailabe(vector<char>& available) {
	for(int i = 0; i < nvar; i++) {
		if(parents[i] == 0){
			available.push_back(returnValueInMap(i));
		}
	}
}

void topological(int pos, string print) {
	if(pos == nvar) {
		cout << print[0];
		for(int i = 1; i < (int) print.length(); i++)
			cout << " " << print[i];
		cout << endl;
		solution = true;
	}

	for(int i = 0; i < nvar; i++) {
		auto it = varmap.find(variables[i]);
		int curr = it->second;
		if(!visited[curr]) {
			if(parents[curr] == 0) {
				for(int j = 0; j < (int) adj[curr].size(); j++) parents[adj[curr][j]]--;

				visited[curr] = true;
				topological(pos+1, print + variables[i]);
				for(int j = 0; j < (int) adj[curr].size(); j++) parents[adj[curr][j]]++;

				visited[curr] = false;
			}
		}
	}
}

int main() {
	int t;

	cin >> t;

	for(int i = 0; i < t; i++) {
		solution = false;
		nvar = 0;
		string s;
		if(i == 0) getline(cin, s);
		getline(cin,s);
		getline(cin,s);

		for(int j = 0; j < (int) s.length(); j++) {
			if(s[j] >= 'A' && s[j] <= 'Z') {
				varmap.insert(make_pair(s[j],nvar));
				variables.push_back(s[j]);
				nvar++;
			}
		}

		getline(cin,s);
		for(int j = 0; j < (int) s.length(); j++) {
			if(s[j] >= 'A' && s[j] <= 'Z') {
				auto it = varmap.find(s[j]);
				auto it2 = varmap.find(s[j+2]);
				adj[it->second].push_back(it2->second);
				parents[it2->second]++;
				j += 2;
			}
		}

		sort(variables.begin(), variables.end());
		printfDebug();
		topological(0, "");

		if(!solution)
			cout << "NO" << endl;

		if(i != t-1) cout << endl;

		clearar();
		printfDebug();

	}

	return 0;
}