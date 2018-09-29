#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;  

int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int n2;
        cin >> n2;

        unordered_map<int,int> m;
        vector<int> v(n2,-1);

        for(int j = 0; j < n2; j++) {
            int x;
            cin >> x;
            
            auto it = m.find(x);

            if(it != m.end()) {
                v[j] = it->second;

                it->second = j;
            }

            else {
                m.insert(make_pair(x,j));
            }
        }

        int p = 0;
        int max = 0;
        int j;

        for (j = 0; j < n2; j++) {

            if (v[j] >= p) {
                if (j-p > max) {
                    max = j-p;
                }
                p = v[j]+1;
            }

        }
 
        if (j-p > max)
            max = j-p;
 
        cout << max << endl;
        
    }
    return 0;
}
