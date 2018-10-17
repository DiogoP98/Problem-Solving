/**
    O(nlog(n)), n numero de caloiros
    
    Para cada caloiro lemos todas as cadeiras em que está inscrito e formamos uma string que contem todos os codigos das cadeiras, estando estes ordenados. 
    Estas strings são adicionadas a um map<string,int> onde a cada string está-lhe atribuida o número de vezes que ocorre.
    Depois é só percorrer o mapa e encontrar o máximo.
*/
#include <bits/stdc++.h>

using namespace std;

int n;

int main () {
    cin >> n;

    while (n != 0) {
        map<string,int> m;
        int count = 1;
        int max = 0;
        for (int i=0;i<n;i++) {
            string a;
            vector<int> x(5);
            for (int j=0; j<5; j++) 
                cin >> x[j];
            
            sort(x.begin(), x.end());
            
            for (int j=0; j < 5; j++) {
                a += to_string(x[j]) + " ";
            }

            map<string, int>::iterator it = m.find(a);

            if (it != m.end()) 
                it->second++;
            else
                m.insert(pair<string,int>(a,1));

        }

        map<string, int>::iterator it = m.begin();

        for (; it!=m.end(); ++it) {
            if (it->second > max){
                count = 1;
                max= it->second;
            }
            else if (it->second == max)
                count++;
        }
        
        if (max != 1)
            cout << max*count << endl;
        else 
            cout << n << endl;

        cin >> n;
    }

    return 0;
}
