#include <cstdio>
#include <vector>
#include 

using namespace std;

struct operation {
	int x1;
	int x2;
	int y1;
	int y2;
	int val;
	char op;
};

bool operator<(operation op1, operation op2) {
	if(op1.y1 == op2.y1) {
		if(o1.type == 'q') return true;
		else return false;
	}

	return op1.y1 > op2.y1;
}

int main() {
	int t;

	scanf("%d", &t);

	vector<operation> v;
	for(int i = 0; i < t; i++) {
		v.clear();
		int n;
		scanf("%d",&n);

		for(int j = 0; j < n; j++) {
			int x, y, val;
			scanf("%d %d %d", &x ,&y ,&val);
			operation op;
			op.x1 = x;
			op.y1 = y;
			op.val = val;
			op.op = 'i';
			v.push_back(op);
		}

		int r;

		scanf("%d", &r);

		for(int j = 0; j < r; j++) {
			int x1,y1,x2,y2;
			scanf("%d %d %d", &x1 ,&y1 ,&x2, &y2);
			op.x1 = x1;
			op.y1 = y1;
			op.x2 = x2;
			op.y2 = y2;
			op.op = 'q';
			v.push_back(op);
		}

		sort(v.begin(), v.end());

		for(int j = 0; j < (int) v.size(); j++) {
			if(v[i].op == 'q')
		}
	}

	return 0;
}