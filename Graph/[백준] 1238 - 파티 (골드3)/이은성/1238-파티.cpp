#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 1000000000

using namespace std;


bool visited[1000];                          //방문 여부
int arr[1000][1000];                         //arr[a][b] = a에서 b까지 가는데 걸

void dijkstra(int n){
    int tmp;
    priority_queue<pair<int, int> >  pq;

    for(int i = 0; i < n; i++){
        fill_n(visited, n, false);
        visited[i] = true;

        for(int j = 0; j < n; j++){    
            pq.push({-arr[i][j], j});
        }

        while(!pq.empty()){
            tmp = pq.top().second;

            if (visited[tmp]){
                pq.pop();
                continue;
            }
            
            visited[tmp] = true;
            pq.pop();
            
            for(int k = 0; k < n; k++){
                if(arr[i][tmp] + arr[tmp][k] < arr[i][k]){
                    arr[i][k] = arr[i][tmp] + arr[tmp][k];
                    pq.push({-arr[i][k], k});
                }
            }
        }
    }

}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m, x; cin >> n >> m >> x;
    int a, b, t;
    int tmp, max;

    for(int i = 0; i < n; i++){
        fill_n(arr[i], n, INF);
        arr[i][i] = 0;
    }

    for(int i = 0; i < m; i++){
        cin >> a >> b >> t;
        arr[a - 1][b - 1] = t;
    }

    dijkstra(n);

    max = 0;

    for(int i = 0; i < n; i ++){
        if(i == (x - 1))
            tmp = 0;
        else
            tmp = arr[i][x - 1] + arr[x - 1][i];

        if(max < tmp)
            max = tmp;
    }

    cout << max;

    return 0;
}
