#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm> 

using namespace std;

map<int, vector<string> > photos;
vector<char> orientation;
vector<string> tags;
vector<bool> used;
vector<string> lastv;
int k, n, last, tused;
char o;
bool worth;

void checkscore() {
	auto it = photos.begin();
	int best = -1000, bestindx;
	vector<string> bestvec;
	int i = 0;

	worth = false;
	for(; it != photos.end() && i < 15000; it++) {
		int curr = it->first;
		vector<string> currvec = it->second;
		i++;

		if(used[curr])
			continue;

		int common = 0;

		for(int k = 0; k < (int) lastv.size(); k++) {
			for(int j = 0; j < (int) currvec.size(); j++) {
				if(lastv[k] == currvec[j])
					common++;
			}
		}

		int def = min((int) lastv.size() - common, min((int) currvec.size() - common, common));

		if(def > best) {
			worth = true;
			best = def;
			bestindx = curr;
			bestvec = currvec;
		}
	}

	if(orientation[bestindx] == 'V' && last != bestindx && !used[bestindx]) {
		used[bestindx] = true;
		for(int i = 0; i < n; i++) {
			if(orientation[i] == 'V' && !used[i]) {
				auto it = photos.find(i);

				if(it != photos.end()) {
					last = i;
					lastv = it->second;
				}

				used[i] = true;

				cout << bestindx << " " << i << endl;

				tused+= 2;
				break;
			}
		}
	}

	else if (last != bestindx && !used[bestindx]) {
		last = bestindx;
		lastv = bestvec;

		cout << last << endl;

		used[last] = true;
		tused++;
	} 

	return;
} 

int checkComb() {
	int total = 0;

	for(int i = 0; i < n; i++) {
		if(orientation[i] == 'H') 
			total++;

		else if(orientation[i] == 'V' && !used[i]) {
			int aux;

			for(int j = i+1; j < n; j++) {
				if(orientation[j] == 'V' && !used[j]) {
					aux = j;
					break;
				}
			}

			total++;
			used[i] = true;
			used[aux] = true;
		}
	}

	return total;
}

int main() {
	cin >> n;

	used.resize(n);

	for(int i = 0; i < n; i++) {
		cin >> o >> k;
		tags.clear();

		for(int j = 0; j < k; j++) {
			string t;
			cin >> t;

			tags.push_back(t);
		}

		photos.insert(make_pair(i,tags));
		orientation.push_back(o);
	}

	int ans = checkComb();

	cout << ans << endl;

	fill(used.begin(), used.end(), false);

	last = 0;
	used[0] = true;
	lastv = photos.begin()->second;
	tused = 1;

	if(orientation[last] == 'V') {
		for(int i = 0; i < n; i++) {
			if (orientation[i] == 'V' && !used[i]) {
				used[i] = true;
				cout << 0 << " " << i << endl;

				auto it = photos.find(i);

				if(it != photos.end()) {
					last = i;
					lastv = it->second;
				}
				tused++;

				break;
			}
		}
	}
	else
		cout << 0 << endl;

	worth = true;

	while(tused != n && worth)
		checkscore();

	if(tused != n) {
		for(int i = 0; i < n; i++) {
			if(!used[i]) {
				if(orientation[i] == 'V') {
					for(int j = i+1; j < n; j++) {
						if(orientation[j] == 'V' && !used[j]) {
							cout << i << " " << j << endl;
							used[i] = true;
							used[j] = true;
							break;
						}
					}
				}
				else {
					cout << i << endl;
					used[i] = true;
				}
			}

		}
	}
}
