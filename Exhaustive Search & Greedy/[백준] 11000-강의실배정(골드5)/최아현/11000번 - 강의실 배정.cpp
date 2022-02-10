#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional> // greater

using namespace std;

bool emp(pair<int,int> &a, pair<int,int> &b) { // 강의 정렬
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int,int>> subject;
	priority_queue<int, vector<int>, greater<int>> room;

	int N, S, T, sw, cnt = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		subject.push_back(pair<int, int>(S, T));
	}

	sort(subject.begin(), subject.end(), emp);

	for (int i = 0; i < subject.size(); i++) {
		if (room.empty()) { // 처음 강의 
			room.push(subject[i].second); // 끝나는 시간 넣음
			cnt++;
		}
		else {
			sw = 0;
			for (int j = 0; j < room.size(); j++) {
				if (room.top() <= subject[i].first) {  // 끝난 강의 확인
					room.pop();                     // 끝났으면 삭제하고 끝나는 시간 넣음
					room.push(subject[i].second);
					sw = 1; // 강의 넣으면 for문 나가기
					break;
				}
			}
			if (sw == 0) { // sw == 0 은 끝난 강의자리가 없음으로 추가
				room.push(subject[i].second);
				cnt++;
			}
		}
	}	

	cout << cnt;
	return 0;
}
// 90% 시간초과

