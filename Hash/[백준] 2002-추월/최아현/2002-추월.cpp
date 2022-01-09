#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {

	int n, count = 0;
	int i, j;
	string s;

	vector<int> out_car;

	cin >> n;

	unordered_map<string, int> hash;
	out_car.insert(out_car.begin(), 0);

	for (i = 1; i <= n; i++) {
		cin >> s;
		hash[s] = i;
	}

	for (j = 1; j <= n; j++) {
		cin >> s;
		out_car.insert(out_car.begin() + j, hash[s]);
	}

	int temp;
	i = 1; 

	while (i <= n) {
		for (int k = 1; k < n - 1; k++) {
			if (out_car[k] > out_car[k + 1]) {
				count++;
				for (j = 1; j < n; j++) {
					if (out_car[j] > out_car[j + 1]) {
						temp = out_car[j];
						out_car[j] = out_car[j + 1];
						out_car[j + 1] = temp;
					}
				}
			}
		}
		i++;
	}

	cout << count;

	return 0;
}