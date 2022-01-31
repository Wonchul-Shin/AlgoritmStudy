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


----------------
#include <cstdio>
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v;

	int N, x;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.insert(v.begin() + i, x); // 값 삽입
	}
	sort(v.begin(), v.end()); // 정렬

	for (int i = 0; i < N; i++) {
		cout << v[i] << '\n';
	}
	return 0;
}
