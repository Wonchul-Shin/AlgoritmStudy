#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
   
	int count[10000] = { 0, }; // counting sort  10,000보다 작거나 같은 자연수
	int N, x, max = 0; // 가장 큰 값까지만 출력하기 위해 max 설정 

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x;
		count[x - 1]++; // 들어오는 자연수 x를 x-1 자리에 삽입
		if (max < x) // max 값 확인
			max = x;
	}
	for (int i = 0; i < max; i++) { //max 값까지  
		if (count[i] != 0) {  // count sort가 빈 값이 아닐 경우
			for (int j = 0; j < count[i]; j++) { // 값(횟수) 만큼 출력
				cout << (i + 1) << '\n';
			}
		}
	}
	return 0;
}