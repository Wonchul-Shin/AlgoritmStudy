#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool visited[102];
vector<int> v[102];


int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t, n;
    int p1, p2;
    int d, tmp;
    bool flag;

    pair<int, int> p[102];
    queue<int> q;

    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n; 
        cin >> p1 >> p2;
        
        p[0] = {p1, p2};
        
        for(int j = 0; j < n; j++){
            cin >> p1 >> p2;
            p[j + 1] = {p1, p2};
        }

        cin >> p1 >> p2;
        p[n + 1] = {p1, p2};

        for(int j = 0; j < n + 2; j++)
            v[j].clear();

        for(int j = 0; j < n + 2; j++){
            for(int k = j + 1; k < n + 2; k++){
                d = abs(p[j].first - p[k].first) + abs(p[j].second - p[k].second);
                if(d <= 1000){
                    v[j].push_back(k);
                    v[k].push_back(j);
                }     
            }
        }

        while(!q.empty())
            q.pop();
        
        memset(visited, false, n + 2);
        q.push(0);
        visited[0] = true;
        flag = false;

        while(!q.empty()){
            tmp = q.front();
            q.pop();

            if(tmp == n + 1){
                flag = true;
                break;
            }

            for(int j = 0; j < v[tmp].size(); j++){
                if(!visited[v[tmp][j]]){
                    q.push(v[tmp][j]);
                    visited[v[tmp][j]] = true;
                }
            }   
        }

        if(flag)
            cout << "happy\n";
        else
            cout << "sad\n"; 
    }


    return 0;
}
