/*#include <iostream>
#include <algorithm>
#include <queue>
#include<string.h>

using namespace std;

bool visited[1001]; // 확인된 위치는 True로 변경
int graph[1001][1001]; // 노드
int N, M;

void Dfs(int v) {
	visited[v] = true;
	cout << v << ' ';
	for (int i = 1; i <= N; i++){
		if (graph[v][i] == 1 && visited[i] == false)
			Dfs(i);
	}
}


void Bfs(int v) {
	int temp;
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cout << temp << ' ';
		for (int i = 1; i <= N; i++) {
			if (graph[temp][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}


int main() {

	int V, x,y;

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	Dfs(V);

	memset(visited, false, sizeof(bool) * (N + 1));
	cout << '\n';
	Bfs(V);

	return 0;
}*/