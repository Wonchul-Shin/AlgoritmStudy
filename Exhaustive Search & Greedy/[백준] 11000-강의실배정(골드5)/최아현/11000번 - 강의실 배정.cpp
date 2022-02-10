#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool emp(pair<int,int> &a, pair<int,int> &b) {
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

	int N, S, T;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> S >> T;
		subject.push_back(pair<int, int>(S, T));
	}

	sort(subject.begin(), subject.end(), emp);

	int sw, cnt = 0;
	vector<int> room;

	for (int i = 0; i < subject.size(); i++) {
		if (room.empty()) {
			room.push_back(subject[i].second);
			cnt++;
		}
		else {
			sw = 0;
			for (int j = 0; j < room.size(); j++) {
				//printf("%d  %d\n", room[j], subject[i].first);
				if (room[j] <= subject[i].first) {
					room.erase(room.begin()+j); 
					room.push_back(subject[i].second);
					sw = 1;
					break;
				}
			}
			if (sw == 0) {
				room.push_back(subject[i].second);
				cnt++;
			}
		}
	}	

	cout << cnt;
	return 0;
}
// 84% 시간초과

