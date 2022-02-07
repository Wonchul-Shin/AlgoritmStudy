#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> h; // 집 위치
vector<pair<int, int>> ck; // 치킨집 위치
vector<int> A; // 조합
vector<int> cklist; // 치킨거리 리스트

void pick_ck() {
	int result = 0;
	
	for (int i = 0; i < h.size(); i++) {
		int min = 1000;
		
		for (int j = 0; j < A.size(); j++) {
			int tp = abs((h[i].first + 1) - (ck[A[j]].first + 1)) + abs((h[i].second + 1) - (ck[A[j]].second + 1));

			if (min > tp) {
				min = tp;
			}
		}
		result += min;
	}
	cklist.push_back(result);
	A.clear();
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x;
	cin >> N >> M;

	vector<int> temp;
	vector<int> s;

	int count = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> x ;
			if (x == 2) {
				ck.push_back(pair<int, int>(i, j));
				s.push_back(cnt);
				cnt++;

				if (count < M) {
					temp.push_back(1);
				}
				else {
					temp.push_back(0);
				}
				count++;
			}
			else if (x == 1) {
				h.push_back(pair<int, int>(i, j));
			}
		}
	}
	do {
		for (int i = 0; i < s.size(); ++i) {
			if (temp[i] == 1)
				A.push_back(s[i]);
		}
		pick_ck();

	} while (prev_permutation(temp.begin(), temp.end()));

	int min = *min_element(cklist.begin(), cklist.end()); // 치킨거리 최소 값

	cout << min;

	return 0;
}
