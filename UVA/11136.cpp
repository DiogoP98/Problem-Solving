#include <iostream>
#include <set>
#include <vector>
#include <functional>

using namespace std;

int n;

int main () {
    cin >> n;

    while (n != 0) {
        int n2;
        multiset<int, greater<int> > v;
        long long t = 0;

        for (int i = 0; i < n; i++) {

            cin >> n2;

            for (int j=0; j < n2; j++) {
                int x;
                cin >> x;

                v.insert(x);
            }

            auto it = v.begin();
            auto itf = v.end();
            --itf;
            
            t += *it-*itf;
            v.erase(it);
            v.erase(itf);
        }
        
        cout << t << endl;
        cin >> n;
    }

    return 0;
}
