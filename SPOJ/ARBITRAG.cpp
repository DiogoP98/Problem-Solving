/**
	Ajudas: https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

	Complexidade: O(n^3), onde n e o numero de currencys

	Explicacao: 

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std; 

#define MAX 35
#define EPS 1e-9

int n, m;
vector<pair<double,int>> adj[MAX];
map<string,int> curr;

bool floydWarshall() {
	vector<vector<double>> cost(MAX, vector<double>(MAX,0.0));
  
    for (int i = 0; i < n; i++) {
    	for(int j = 0; j < (int) adj[i].size(); j++) {
    		int a = adj[i][j].second; 
    		double v =  adj[i][j].first;
    		cost[i][a] = v;
    	}
    }

    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {  
                if (cost[i][k] * cost[k][j] > cost[i][j]) 
                    cost[i][j] = cost[i][k] * cost[k][j]; 
            	} 
        }
    }

    for(int i = 0; i < n; i++) {
    	if(cost[i][i] > 1.0)
    		return true;
    }

    return false;
} 

int main() {
	cin >> n;
	string s, s1, s2;
	int j = 0;

	while(n != 0) {
		j++;
		for(int i = 0; i < n; i++) {
			cin >> s;
			curr.insert(make_pair(s,i));
		}

		cin >> m;
		double v;

		for(int i = 0; i < m; i++) {
			cin >> s1 >> v >> s2;

			auto it = curr.find(s1);
			auto it2 = curr.find(s2);

			//cout << it->second << "  " << it2->second << "   " << v << endl;
			adj[it->second].push_back(make_pair(v,it2->second));
		}

		bool ans = floydWarshall();

		if(ans)
			cout << "Case " << j << ": Yes" << endl;
		else
			cout << "Case " << j << ": No" << endl;

		for(int i = 0; i < n; i++) 
			adj[i].clear();

		curr.clear();

		cin >> n;
	}

}
