#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[100000];
bool done[100000];
int graph[100000];
int count;

void dfs(int st){
    visited[st] = true;

    if(!visited[graph[st]])
        dfs(graph[st]);
    else if(!done[graph[st]]){
        for(int i = graph[st]; i != st; i = graph[i])
            count++;
        count++;
    }
    done[st] = true;
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t, n, input; cin >> t;

    for(int j = 0; j < t; j++){
        cin >> n;
        count = 0;
        memset(done, false, n);
        memset(visited, false, n);

        for(int i = 0; i < n; i++){
            cin >> input;
            graph[i] = input - 1;
        }


        for(int i = 0; i < n ; i++){
            if(!visited[i]){
                dfs(i);
            }
        }

        cout << n - count << '\n';

    }

    return 0;
}
