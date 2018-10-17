/**
    O(m * nlogn), n é o número de registos e m o núermo de queries.
    Guardamos numa priority_queue os pares (tempo,id), onde tempo é o tempo que demora a retornar o resultado. Mantemos também num mapa o tempo de cada id.
    Executamos depois as m queries retirando sempre o primeiro elemento da priority_queue, e voltando-o a adicionar com o tempo atual mais o tempo que ele demora
    a retornar o resultado(valor que está guardado no mapa). 
*/

#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;

string reg;

int main() {
     priority_queue < pair<int,int> , vector < pair<int,int> > , greater< pair<int,int> > > pq;
     unordered_map<int,int> m;

    cin >> reg;
    while (reg.compare("#")!=0)  {
        int id, p;
        cin >> id >> p;
        
        m.insert(make_pair(id,p));

        pq.push(make_pair(p,id));

        cin >> reg;
    }

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tempo = pq.top().first;
        int id = pq.top().second;

        pq.pop();
        cout << id << endl;

        pq.push(make_pair(tempo+m[id],id));
    }

    return 0;
}
