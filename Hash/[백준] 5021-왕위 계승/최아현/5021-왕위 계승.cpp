#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	int n, m;
	string s;
	string p1, p2;
	
	string king;

	unordered_map<string, double> hash;
	vector<string> v;

	cin >> n >> m;
	cin >> s;

	hash[s] = 1.0;

	for (int i = 0; i < n ; i++) {
		
		cin >> s >> p1 >> p2;
		if (hash[p1] != NULL && hash[p2] != NULL) {
			hash[s] = hash[p1] + hash[p2];
		}
		else if (hash[p1] != NULL) {
			hash[s] = hash[p1] / 2;
		}
		else if (hash[p2] != NULL) {
			hash[s] = hash[p2] / 2;
		}
		else {
			hash[s] = 0.0;
		}
	}

	for (int j = 0; j < m; j++) {
		cin >> s;
		v.insert(v.begin() + j, s);
	}
	king = v[0];

	for (int k = 1; k < m; k++) {
		if (hash[king] < hash[v[k]])
			king = v[k];
	}

	cout << king;

	return 0;
}