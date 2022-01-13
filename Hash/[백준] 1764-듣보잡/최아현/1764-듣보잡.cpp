#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int main() {

	int n, m, count = 0;
	string s;

	cin >> n >> m;

	unordered_map<string, bool> hash_i;
	unordered_map<int, string> hash_o;
	vector<string> see;

	for (int i = 0; i < n; i++) {

		cin >> s;
		hash_i[s] = true;
	}
	for (int j = 0; j < m; j++) {

		cin >> s;
		if (hash_i[s]){
			see.insert(see.begin()+count, s);
			count++;	
		}
	}

	string tmp;
	sort(see.begin(), see.end());


	cout << count << endl;
	for (int k = 0; k < count; k++) {
		cout << see[k] << endl;
	}

	return 0;
}
