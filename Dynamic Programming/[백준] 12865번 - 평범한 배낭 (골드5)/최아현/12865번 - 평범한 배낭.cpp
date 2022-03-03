/*#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int N, K, w, v, result = 0;

	cin >> N >> K;

	vector<pair<int, int>> bag(N); //물건
	vector<int> dp_w[101]; // 무게
	vector<int> dp_v[101]; // 가치

	for (int i = 0; i < N; i++) {
		cin >> w >> v;
		bag[i] = pair<int, int> (w, v);
	}

	dp_w[0].push_back(bag[0].first); // 맨 처음 물건
	dp_v[0].push_back(bag[0].second);

	for (int a = 1; a < N; a++) {

		for (int i = 0; i < a ; i++) {

			dp_w[a].push_back(bag[a].first + bag[i].first); // 첫번째 물건
			dp_v[a].push_back(bag[a].second + bag[i].second);

			for (int j = 0; j < dp_v[i].size(); j++) {
				int x = 0;

				if (bag[a].first + dp_w[i][j] <= K) { // 물건들의 누적 무게를 가진 dp와 차례대로 비교
					dp_w[a].push_back(bag[a].first + dp_w[i][j]);
					dp_v[a].push_back(bag[a].second + dp_v[i][j]);
					x = bag[a].second + dp_v[i][j];
				}
				else { // K보다 크면 그냥 자신의 무게와 가치만 대입
					dp_w[a].push_back(bag[a].first);
					dp_v[a].push_back(bag[a].second);
					x = bag[a].second;
				}
				if(result < x){
					result = x;
				}
			}
		}
	}
	cout << result;

	return 0;
}*/