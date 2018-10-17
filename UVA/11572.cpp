/**
    O(nlogn), n numero de flocos de neve

    Guardamos num mapa cada valor diferente de flocos de neve e a última posição em que apareceram. Se o valor já estiver no mapa guardamos num array v[j] = k,
    onde j é a posição atual e k a última posição onde esse mesmo floco de neve tinha aparecido antes.
    Assim, após lermos todos os valores de flocos de neve começamos a analisar as sequências possives. Começamos pela posição 0, e quando encontrarmos uma posição cujo floco existe anteriormente na sequência verificamos se a sequência
    atual é maior que o máximo, e executamos este processo até ao último floco.
*/

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
