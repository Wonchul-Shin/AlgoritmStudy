#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, x, y;
	priority_queue<int> pq;

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> x;

		if (x == 0) { // 들어오는 값이 인지 x 값인지 확인
			if (pq.empty()) { //0이면 빈 큐일 때 -1 출력
				cout << -1 << "\n"; 
				}
			else { // 아닐 때 top 값 출력 후 pop
				cout << pq.top() << "\n";
				pq.pop();
				}
		}
		else {
			for (int j = 0; j < x;  j++) { // 들어오는 값이 x 값이면
				cin >> y; // x 번 만큼 for문으로 큐에 넣기
				pq.push(y);
			}
		}
	}
	return 0;
}