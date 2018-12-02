#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> st(MAX);

int merge(int a, int b) {
	return max(a,b);
}

void build(int node, int start, int end) {
	if (start == end)
		st[node] = freq[start];

	else {
		int m = start + (end-start)/2;
		build(node*2,start, m);
		build(node*2+1,m+1, end);
		st[node] = merge(st[node*2], st[node*2+1]);		
	}
}

int query(int node, int start, int end, int x, int y) {
	if (y < start  || end < x) return 0;

	if(start>=x && end <= y) return st[node];

	int m = start + (end-start)/2;
	int a = query(node*2, start, m, x, y);
	int b = query(node*2+1, m+1, end, x, y);

	return merge(a,b);
}

void calculate(int l, int h, vector<int>& c) {
	long long int ac = 0;
	long long int result = 0;
	long long int md = 10e9+7;

	sort(c.begin()+l-1,c.begin()+h, greater<int>());

	for(int i = l-1; i < h; i++){
		result += c[i] + ac;
		ac += c[i] + ac;
	}
	cout << result%md << endl;
}

int main() {
	int q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> d(n+5);
	for(int i = 0; i < (int) s.length(); i++) d[i+1] = (int) s[i]- '0';

	build(d,1,1,n)

	for(int i = 0; i < q; i++) {
		int l, h;
		cin >> l >> h;
		calculate(l,h,c);
		c = d;
	}

	return 0;
}