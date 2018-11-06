/**
    Complexidade: 
    
    Ajudas: https://www.geeksforgeeks.org/two-dimensional-segment-tree-sub-matrix-sum/

*/


#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 20005

int maxtree[MAX][MAX];
int mintree[MAX][MAX];
int n,m;
int min = INT_MAX;
int max = 0;

int merge (int a, int b){
    return a+b;
}

void build_x(int node, int l, int h, vector<vector<int>> v) {
    if (l != h) {
        int m = l + (h - l) / 2;
        build_x(node*2, l, m,v);
        build_x(node*2+1, m+1, h,v);
    }
    build_y(node, l, h, 1, 0, m-1,v);
} 

void build_y(int nodex, int lx, int hx, int nodey, int ly, int hy, vector<vector<int>> v) {
    if (ly == hy) {
        if (lx == hx) {
            maxtree[nodex][nodey] = v[lx][ly];
            mintree[nodex][nodey] = v[lx][ly];
        }
        else{
            maxtree[nodex][nodey] = max(maxtree[nodex*2][nodey] + maxtree[nodex*2+1][nodey]);
            mintree[nodex][nodey] = min(mintree[nodex*2][nodey] + mintree[nodex*2+1][nodey]);
        }
    } else {
        int m = (ly + ry) / 2;
        build_y(nodex, lx, rx, nodey*2, ly, m);
        build_y(nodex, lx, rx, nodey*2+1, m+1, hy);
        maxtree[nodex][nodey] = max(maxtree[nodex][nodey*2] + maxtree[nodex][nodey*2+1]);
        mintree[nodex][nodey] = min(mintree[nodex][nodey*2] + mintree[nodex][nodey*2+1]);
    }
}

pair<int,int> query_y(int nodex, int nodey, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return make_pair(0, INT_MAX);
    if (ly == tly && try_ == ry)
        return make_pair(maxtree[nodex][nodey],mintree[nodex][nodey]);
    int tmy = (tly + try_) / 2;

    pair<int,int> p1 = query_y(nodex, nodey*2, tly, tmy, ly, min(ry, tmy));
    pair<int,int> p2 = query_y(nodex, nodey*2+1, tmy+1, try_, max(ly, tmy+1), ry);
    
    return make_pair(max(p1.first,p2.first), min(p1.second,p2.second));
}

pair<int,int> query_x(int nodex, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return 0;
    if (lx == tlx && trx == rx)
        return sum_y(nodex, 1, 0, m-1, ly, ry);
    int tmx = (tlx + trx) / 2;

    pair<int,int> p1 = query_x(nodex*2, tlx, tmx, lx, min(rx, tmx), ly, ry);
    pair<int,int> p2 = query(nodex*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);

    return make_pair(max(p1.first,p2.first), min(p1.second,p2.second));
}

void update_y(int nodex, int lx, int hx, int nodey, int ly, int hy, int x, int y, int new_val) {
    if (ly == hy) {
        if (lx == hx) {
            maxtree[nodex][nodey] = new_val;
            mintree[nodex][nodey] = new_val;
        }
        else {
            maxtree[nodex][nodey] = max(maxtree[nodex*2][nodey],maxtree[nodex*2+1][nodey]);
            mintree[nodex][nodey] = min(mintree[nodex*2][nodey],mintree[nodex*2+1][nodey]);
        }
    } else {
        int m = ly + (hy - ly) / 2;
        if (y <= m)
            update_y(nodex, lx, hx, nodey*2, ly, m, x, y, new_val);
        else
            update_y(nodex, lx, hx, nodey*2+1, m+1, hy, x, y, new_val);
        maxtree[nodex][nodey] = max(maxtree[nodex][nodey*2], maxtree[nodex][nodey*2+1]);
        mintree[nodex][nodey] = min(mintree[nodex][nodey*2], mintree[nodex][nodey*2+1]);
    }
}

void update_x(int nodex, int lx, int hx, int x, int y, int new_val) {
    if (lx != hx) {
        int mx = (lx + hx) / 2;
        if (x <= mx)
            update_x(nodex*2, lx, mx, x, y, new_val);
        else
            update_x(nodex*2+1, mx+1, hx, x, y, new_val);
    }
    update_y(nodex, lx, hx, 1, 0, m-1, x, y, new_val);
}

int main() {
	cin >> n;

	vector<vector<int>> m(n);
	for(int i = 0; i < n; i++) {
		m[i].resize(n);
		for(int j = 0; j < n; j++)
			cin >> m[i][j];
        build_x(0,n-1,1,i,m);
	}

    build_y(0,n-1,1);

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		string s;

		cin >> s;

		if(s == "q") {
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
            pair<int,int> ans = query_x(1,0,n-1,y1,y2,x1,x2);
            cout << ans.first << " " << ans.second << endl;
		}
        else {
            int x, y, val;
            cin >> x >> y >> val;
            update_x(1,0,n-1,x,y,val);
        }
	}
}