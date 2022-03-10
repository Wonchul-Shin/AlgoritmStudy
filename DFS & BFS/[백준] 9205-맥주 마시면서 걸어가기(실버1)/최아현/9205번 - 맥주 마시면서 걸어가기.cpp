/*
#include <iostream>
#include <vector>
#include<string.h>

using namespace std;

int visited[100] = { 0, }; // 벡터 인덱스
vector<pair<int, int>> store;
int feel = 0; // 0 = sad 1 = happy
int x, y;

void bfs(int a, int b) {
	int dist;

	dist = abs(x - a) + abs(y - b);

	if (feel == 1 || dist <= 1000) {
		feel = 1;
		return;
	}

	for (int i = 0; i < store.size(); ++i) {
		if (visited[i] == 1) {
			continue;
		}

		dist = abs(store[i].first - a) + abs(store[i].second - b);

		if (dist > 1000) {
			continue;
		}
		else {
			visited[i] = 1;
			bfs(store[i].first, store[i].second);
		}
	}
}

int main() {

	int T, N;
	int homex, homey;

	cin >> T; // 테스트 케이스

	for (int t = 0; t < T; t++) {
		store.clear();
		memset(visited, 0, sizeof(visited));

		feel = 0;
		cin >> N; // 편의점 갯수

		cin >> homex >> homey; // 집 위치

		for (int i = 0; i < N; i++) {
			cin >> x >> y;
			store.push_back(make_pair(x,y));
		}

		cin >> x >> y; // 페스티벌 위치
		
		//sort(store.begin(), store.end(), cmp);
		bfs(homex, homey);

		if (feel == 1)
			cout << "happy\n";
		else cout << "sad\n";
	}
	return 0;
}*/