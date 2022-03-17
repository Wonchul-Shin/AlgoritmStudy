#include <iostream>
#include <queue>
using namespace std;
int N, M, V;
int map[1001][1001];
int used[1001];
void DFS(int s) {
	cout << s << " ";
	used[s] = 1;
	for (int i = 1;i <= N;i++) {
		if (map[s][i] == 0) continue;
		if (used[i] == 1) continue;

		DFS(i);
	}
}
queue<int> q;
int usedbfs[1001];
void BFS(int s) {
	q.push(s);
	usedbfs[s] = 1;
	while (!q.empty()) {
		int a = q.front();
		cout << a << " ";
		q.pop();
		for (int i = 1;i <= N;i++) {
			if (usedbfs[i] == 1) continue;
			if (map[a][i] == 1) {
				q.push(i);
				usedbfs[i] = 1;
			}
		}
	}

}
int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);

	cin >> N >> M >> V;
	for (int i = 0;i < M;i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	DFS(V); cout << "\n";
	BFS(V);
	return 0;
}