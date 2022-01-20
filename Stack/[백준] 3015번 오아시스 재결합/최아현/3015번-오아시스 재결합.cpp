#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	int in;
	vector<int> v;

	int point = 0;
	int result = 0;
	int sw = 0;
	int count = 0;
	cin >> N;

	for (int i = 0; i < N; i++) { // 맨 앞사람부터 뒷사람을 한명씩 확인하면서 
		cin >> in;                // 그 사이에 큰사람이 없으면 +1해서 총 값을 result에 저장
		v.insert(v.begin() + i, in); 
	}

	while (point < N) {

		for (int i = point + 2; i < N; i++) {  // 바로 앞사람은 보이니깐 마지막에 한꺼번에 + 해주고 
			count = 0;                         // 그 다음사람 부터 확인
			for (int j = point + 1; j < i; j++) {
				if (v[point] < v[j] || v[i] < v[j]) {  //두 사람 사이에 A 또는 B보다 키가 큰 사람이 없어야 한다
					break;
				}
				if (j == i - 1){ //for문이 다 돌아갈 때까지 break안 나가면 +1 
					count++;
				}
			}
			result += count;
		}
		point++;
	}

	cout << result + (N-1);

	return 0;
}
