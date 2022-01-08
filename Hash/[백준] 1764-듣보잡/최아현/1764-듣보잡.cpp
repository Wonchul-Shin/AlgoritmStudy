#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int n, m, count = 0;
	string s;

	cin >> n >> m;

	unordered_map<string, bool> hash_i;
	unordered_map<int, string> hash_o;

	for (int i = 0; i < n; i++) {

		cin >> s;
		hash_i[s] = true;
	}
	for (int j = 0; j < m; j++) {

		cin >> s;
		if (hash_i[s]){
			count++;	
			hash_o[count] = s;
		}
	}

	cout << count << endl;
	for (int k = 1; k <= count; k++) {

		cout << hash_o[k] << endl;
	}

	return 0;
}
