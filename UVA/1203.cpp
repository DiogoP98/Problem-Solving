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
