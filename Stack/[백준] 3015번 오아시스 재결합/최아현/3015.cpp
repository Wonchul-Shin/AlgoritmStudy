/*#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int n;
long long result;
stack<pair<long long, long long>> s; //Å°, Áßº¹µÈ °³¼ö

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long h;
		cin >> h;

		int count = 1;
		while (!s.empty()) {
			if (s.top().first < h) {
				result += s.top().second;
				count = 1;
				s.pop();
			}
			else if (s.top().first == h) {
				result += s.top().second;
				count = s.top().second + 1;
				s.pop();
			}
			else {
				result++;
				break;
			}
		}
		s.push(make_pair(h, count));
	}

	cout << result;

	return 0;
}*/
