#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int count = 0, ans = 1; 

int main() {
	long long int n;
	cin >> n;

	int op = 0;

	while(true) {
		bool changed = false;
		long long int p = sqrt(n);
		if(p*p == n) { n = p; op++;}
		else {
			map<long long int,int> m;
			long long int n2 = n;
			while (n2%2 == 0) { 
        		map<long long int, int>::iterator it = m.find(2); 
				if (it != m.end())
    				it->second = it->second+1;
    			else
    				m.insert(make_pair(2,1));
        		n2 = n2/2; 
    		} 
   
    		for (int i = 3; i <= sqrt(n2); i = i+2) {  
        		while (n2%i == 0) { 
           			map<long long int, int>::iterator it = m.find(i); 
					if (it != m.end())
    					it->second = it->second+1;
    				else
    					m.insert(make_pair(i,1)); 
        			n2 = n2/i;  
        		} 
    		} 
   
    		if (n2 > 2) { 
        		map<long long int, int>::iterator it = m.find(n2); 
				if (it != m.end())
    				it->second = it->second+1;
    			else
    				m.insert(make_pair(n2,1));
    		}
    		else {
    			map<long long int, int>::iterator it = m.find(2);
    			if (it != m.end())
    				it->second = it->second+1;
    			else
    				m.insert(make_pair(2,1));
    		}	

			map<long long int, int>::iterator it = m.begin();

			long long int mul = 1;
			for (; it != m.end(); it++) {
	    		if(it->second%2 != 0) {
	    			mul *= it->first; 
	    			cout << it-> first << " " << it->second << endl;
	    			changed = true;
	    		}
			}

			if(!changed) break;
			else {
				if(sqrt(n*mul) > n) break;
				n *= mul;
				op++;
			}
		}
	}

	cout << n << " " << op << endl;	

	return 0;
}