#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int n, m, count = 0;
	string s;

	cin >> n >> m;

	unordered_map<string, bool> hash;

	for (int i = 0; i < n; i++) {

		cin >> s;
		hash[s] = true;
	}
	for (int j = 0; j < m; j++) {

		cin >> s;
		if (hash[s])
			count++;
	}
	cout << count;
	return 0;
}


