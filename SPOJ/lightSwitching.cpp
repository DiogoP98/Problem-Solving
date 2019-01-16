/**
    Complexidade: O(n + logn), n numero de estabulos

    Quando se trata de um update, vamos percorrer os intervalos da segment tree até encontrar o nó 
    que pretendemos, onde lhe alteramos o valor e propagamos aos filhos. Se no caminho até este nó
    houverem nós que tenham sido propagados e o valor não tenha sido alterado, alteramos durante esta procura
    e propagamos para os filhos. No entanto os valores so sao alterados se nos intervalos acima do intervalo
    que prentedemos alterar, tenham sido alterados um número impar de vezes, visto que só assim é que as luzes
    mudam de estado.
    Quando se trata de uma query fazemos o meso no que toca a lazy propagation e depois vamos procurar o intervalo
    [x,y] e calcular o valor pretendido.
*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 2000005

vector<int> lazy(MAX,0);
vector<int> st(MAX);

/*
void printTreeForDebug(int node, int start, int end) {
    if(start != end) {
        int m = start + (end-start)/2;
        printTreeForDebug(node*2,start, m);
        printTreeForDebug(node*2+1,m+1, end);
    }
    cout << "node: " << node << "  " << start << "," << end << "     :" << st[node] << endl;
}
*/

int merge(int a, int b) {
    return a+b;
}

void build(int node, int start, int end) {
    if (start == end) {
        st[node] = 0;
    }

    else {
        int m = start + (end-start)/2;
        build(node*2,start, m);
        build(node*2+1,m+1, end);
        st[node] = merge(st[node*2], st[node*2+1]);
    }

    //cout << "node: " << node << "  " << start << "," << end << "     :" << st[node] << endl;
}

void lazyProp(int node, int start, int end, int a, int b) {

    if(lazy[node] != 0) {
        if(lazy[node] % 2 != 0 ) {
            st[node] = (end-start)+ 1 - st[node];

            if(start != end) {
                //printf("here [%d,%d] %d %d\n", start, end, node*2,node*2+1);
                lazy[node*2] += 1;
                lazy[node*2+1] += 1;
            }
        }

        lazy[node] = 0;
    }

    if(b < start || a > end)
        return;

    if(start >= a && end <= b) {
        st[node] = (end-start) + 1 - st[node];

        if(start != end){
            //printf("here2 [%d,%d] %d %d\n", start, end, node*2,node*2+1);
            lazy[node*2] += 1;
            lazy[node*2+1] += 1;
            //cout << "a: " << a << "  b: " << b << " node1: " << node*2 << " " << "node2: " << node*2+1 << " node: " << node << endl;
        }
        //cout << "-----------Update------------" << a << " " << b << endl;
        //cout << "node: " << node << "  " << start << "," << end << "     :" << st[node] << endl;

        return;
    }

    int mid = start + (end - start) / 2;
    //cout << "mid: " << mid << "   " << start << "  " << end << endl;
    lazyProp(node*2, start, mid, a, b); 
    lazyProp(node*2 + 1, mid + 1, end, a, b);
    st[node] = merge(st[node*2], st[node*2+1]);    
}

int query(int node, int start, int end, int a, int b){

    //cout << node << " " << lazy[node] << endl;
    if(lazy[node] != 0) {
        if(lazy[node] % 2 != 0 ) {
            st[node] = (end-start)+ 1 - st[node];
        
            //cout << "node updated: " << node << endl;

             if(start != end) {
            //printf("here3 [%d,%d] %d %d\n", start, end, node*2,node*2+1);
                lazy[node*2] += 1;
                lazy[node*2+1] += 1;
            }
        }

        lazy[node] = 0;
    }

    if(start > b || a > end)
        return 0;

    //cout << "----------Query-------------" << endl;
    //cout << "node: " << node << "  " << start << "," << end << "     :" << st[node] << endl;

    if(start >= a && end <= b) return st[node];

    int mid = start + (end - start) / 2;

    if(b <= mid)
        return query(node*2, start, mid, a, b);

    if(a > mid)
        return query(node*2 + 1, mid + 1, end, a, b);

    int p1 = query(node*2, start, mid, a, b);
    int p2 = query(node*2 + 1, mid + 1, end, a, b);
    return merge(p1,p2);
}

int main() {
    int n,m;
    cin >> n >> m;
    build(1,1,n);
    for(int i = 0; i < m; i++) {
        int op,x,y;
        scanf("%d %d %d", &op, &x, &y);

        if(op == 0)lazyProp(1,1,n,x,y);
        else{
            int k = query(1,1,n,x,y);
            printf("%d\n", k);
        }
        //printTreeForDebug(1,1,n);
        //cout << "-----------------" << endl;
    }
}