#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int n, k;
	queue<int> q;
	vector<int> v;

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int b = 0;
	int a = 1;
	while (1) {
		if (q.empty()) { // 큐가 비었을 때 while 나가기
			break;
		}
		if (a == k) { // k번째 자리 값 pop()하면서 벡터에 저장
			v.insert(v.begin() + b, q.front());	// 제거되는 순으로 배열 저장
			q.pop();
			a = 1; // 자리 1로 초기화
			b++; //벡터인덱스 ++
			continue;
		}
		else { // k번째 자리가 아니면 push - pop		
			q.push(q.front());
			q.pop();
			a++;//자리 증가
		}
	}
	//----------------벡터 출력
	printf("<%d", v[0]);
	for (int j = 1; j < b; j++) {

		printf(", %d", v[j]);
	}
	printf(">");
}


