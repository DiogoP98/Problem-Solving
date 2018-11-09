#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;	

int n;

vector<int> sequence(vector<int> values) {
  	vector<int> ind; 
  	vector<int> leng(n+5,0); 
    for (int i = 0; i < n; i++) { 
        int x = lower_bound(ind.begin(), ind.end(), values[i]) - ind.begin();
        if (x == ind.size()) ind.push_back(values[i]);
        else ind[x] = values[i];

        leng[i] = x + 1;
    } 
  
    return leng;
}

vector<int> sequence2(vector<int> values) {
	vector<int> ind; 
  	vector<int> leng(n+5,0);
   
    for (int i = n-1; i >=0 ; i--) { 
        int x = lower_bound(ind.begin(), ind.end(), values[i]) - ind.begin();
        if (x == ind.size()) ind.push_back(values[i]);
        else ind[x] = values[i];

        leng[i] = x + 1;
    } 
  
    return leng;
}


int main() {

	while( scanf("%d", &n) != EOF ) {
		vector<int> values(n+5);

		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			values[i] = x;
		}

		vector<int> seq = sequence(values);
		vector<int> seq2 = sequence2(values);

		/*
		for(int i = 0; i < n; i++) printf("%d ", seq[i]);
		printf("\n");
		for(int i = 0; i < n; i++) printf("%d ", seq2[i]);
		printf("\n");
		*/		

		int ans = 1;

		for(int i = 0; i < n; i++) ans = max(ans,min(seq[i], seq2[i]) * 2 - 1); 

		cout << ans << endl;
	}
	
	return 0;
}