#include <cstdio>
#include <iostream>
#include <queue>
#include <functional> // greater

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	int N, x; 

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		pq.push(x);
	}
	for (int i = 0; i < N; i++) { 
		cout << pq.top() << '\n';
		pq.pop();
	}
	return 0;
}
