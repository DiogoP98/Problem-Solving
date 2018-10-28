#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

#define MAX 2000005

int ytree[MAX][MAX] = {};
int ftree[MAX][MAX] = {};

int build_y(int low, int high, int pos, int strip) 
{ 
    if (high == low) { 
       ytree[strip][pos] = rect[strip][low]; 
    } 
    else { 
        int mid = (low + high) / 2; 
        segment(low, mid, 2 * pos, strip); 
        segment(mid + 1, high, 2 * pos + 1, strip); 
       	ytree[strip][pos] =ytree[strip][2 * pos] + 
                             ytree[strip][2 * pos + 1]; 
    } 
} 

int build_x(int low, int high, int pos) 
{ 
    if (high == low) { 
  
        for (int i = 1; i < 2 * size; i++) 
            ftree[pos][i] =ytree[low][i]; 
    } 
    else { 
        int mid = (low + high) / 2; 
        finalSegment(low, mid, 2 * pos); 
        finalSegment(mid + 1, high, 2 * pos + 1); 
  
        for (int i = 1; i < 2 * size; i++) 
            ftree[pos][i] = ftree[2 * pos][i] +  
                              ftree[2 * pos + 1][i]; 
    } 
} 

int query_x(int pos, int start, int end, int x1, int x2, int node) 
{ 
    if (x2 < start || end < x1) { 
        return 0; 
    } 
  
    if (x1 <= start && end <= x2) { 
        return ftree[node][pos]; 
    } 
  
    int mid = (start + end) / 2; 
    int p1 = query_x(2 * pos, start, mid, 
                        x1, x2, node); 
  
    int p2 = query_x(2 * pos + 1, mid + 1, 
                        end, x1, x2, node); 
  
    return (p1 + p2); 
}

int query_y(int pos, int start, int end, 
          int y1, int y2, int x1, int x2) 
{ 
    if (y2 < start || end < y1) { 
        return 0; 
    } 
  
    if (y1 <= start && end <= y2) { 
        return (query_x(1, 1, 4, x1, x2, pos)); 
    } 
  
    int mid = (start + end) / 2; 
    int p1 = query_y(2 * pos, start, 
                   mid, y1, y2, x1, x2); 
    int p2 = query_y(2 * pos + 1, mid + 1, 
                   end, y1, y2, x1, x2); 
  
    return (p1 + p2); 
} 

int update_y(int pos, int low, int high, 
                int x, int val, int node) 
{ 
    if (low == high) { 
        ftree[node][pos] = val; 
    } 
    else { 
        int mid = (low + high) / 2; 
  
        if (low <= x && x <= mid) { 
            update_x(2 * pos, low, mid, x, val, node); 
        } 
        else { 
            update_x(2 * pos + 1, mid + 1, high,  
                                     x, val, node); 
        } 
  
        ftree[node][pos] = ftree[node][2 * pos] +  
                             ftree[node][2 * pos + 1]; 
    } 
} 
  
int update_x(int pos, int low, int high, int x, int y, int val) { 
    if (low == high)
        update_x(1, 1, 4, x, val, pos); 

    else { 
        int mid = (low + high) / 2; 
  
        if (low <= y && y <= mid) { 
            update(2 * pos, low, mid, x, y, val); 
        } 
        else { 
            update(2 * pos + 1, mid + 1, high, x, y, val); 
        } 
  
        for (int i = 1; i < size; i++) 
            ftree[pos][i] = ftree[2 * pos][i] +  
                              ftree[2 * pos + 1][i]; 
    } 
} 

int main() {
	int n;

	cin >> n;

	vector<vector<int>> m(n);
	for(int i = 0; i < n; i++) {
		m[i].resize(n);
		for(int j = 0; j < n; j++)
			cin >> m[i][j];
	}

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		string s;

		cin >> s;

		if(S == "q") {
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
		}
	}
}