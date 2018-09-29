#include <iostream>
#include <set>
#include <vector>
#include <functional>

using namespace std;

int main(){
    int n,b,sg,sb;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> b >> sg >> sb;
        multiset<int, greater<int> > green;
        multiset<int, greater<int> > blue;
        int x;

        for (int j=0; j < sg; j++) {
            cin >> x;
            green.insert(x);
        }

        for (int j=0; j < sb; j++) {
            cin >> x;
            blue.insert(x);
        }
        
        bool end = false;
        while (!end) {

            vector<int> r(b,0);

            for (int j=0; j < b; j++) {

                if (green.size() == 0 || blue.size() == 0) { //nao ha suficientes para atribuir a outros battlefields
                    break;
                }

                auto it = green.begin();
                auto it2 = blue.begin();

                r[j] = *it-*it2;

                green.erase(it);
                blue.erase(it2);
            }

            for (int j=0; j < b; j++) {
                if (r[j] > 0)
                    green.insert(r[j]);
                else if (r[j] < 0) 
                    blue.insert(abs(-r[j]));
            }

            if (green.size() == 0 && blue.size() == 0) {
                cout << "green and blue died" << endl;
                end=true;
            }

            else if (green.size() == 0) {
                cout << "blue wins" << endl;

                for (int x: blue) {
                    cout << x << endl;
                }

                end=true;
            }
            
            else if (blue.size() == 0) {
                cout << "green wins" << endl;

                for (int x: green) {
                    cout << x << endl;
                }

                end=true;
            }
        }
        if (i != n-1)
            cout << endl;
    }

    return 0;
}
