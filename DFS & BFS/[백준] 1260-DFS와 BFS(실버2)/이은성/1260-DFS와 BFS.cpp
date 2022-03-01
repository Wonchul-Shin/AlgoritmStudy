#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int graph[1001][1001];
bool visited[1001];
int n, m, v;

void dfs(int v){
    visited[v] = true;
    cout << v << ' ';
    for(int i = 1; i <= n; i++){
        if(graph[v][i] == 1 && visited[i] == false){
            dfs(i);
           
        }
    }
}

void bfs(int v){
    int tmp;
    queue<int> q;

    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        cout << tmp << ' ';
        for(int i = 1; i <= n; i++){
            if(graph[tmp][i] == 1 && visited[i] == false){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int v1, v2;

    cin >> n >> m >> v;

    for(int i = 0; i < m; i++){
        cin >> v1 >> v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }

    
    dfs(v);
    memset(visited, false, sizeof(bool) * (n + 1));
    cout << '\n';
    bfs(v);
    
    return 0;
}