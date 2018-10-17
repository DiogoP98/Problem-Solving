/**
    O(nlog(n))

    Para cada operação vamos adicionado ou removendo de cada uma das estruturas de dados. Guardamos também um booleano para cada estrutura e cada vez que uma operação esteja errada
    mudamos o valor desse booleano. No fim é só verificar o valor de cada booleano.
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

int n;

int main () {

    while(scanf("%d", &n) != EOF ) {
        bool pri = true;
        bool s = true;
        bool q = true;
        
        queue<int> qu;
        priority_queue<int> pq;
        stack<int> st;


        for (int i=0; i < n; i++) {
            int c1, a;

            cin >> c1 >> a;

            int x = -1;

            if (c1 == 1) {
                if (pri) 
                    pq.push(a);
                
                if (s)
                    st.push(a);

                if (q)
                    qu.push(a);
            }

            if (c1 == 2) {
                if (pri) {
                    if (!pq.empty())
                         x = pq.top();

                    if (x != a) 
                        pri=false;
                    else
                        pq.pop();
                }

                if (s) {
                    if (!st.empty())
                        x = st.top();

                    if (x != a) 
                        s=false;
                    else
                        st.pop();
                }

                if (q) {
                    if (!qu.empty())
                        x = qu.front();
                        
                    if (x != a) 
                        q=false;
                    else
                        qu.pop();
                }
            }
        }

        if (!q && !s && !pri) 
            cout << "impossible" << endl;
        
        if ((pri && q) || (pri && s) || (s && q))
            cout << "not sure" << endl;
        else if (pri)
            cout << "priority queue" << endl;
        else if (q)
            cout << "queue" << endl;
        else if (s)
            cout << "stack" << endl;
    }
    
    return 0;
}

