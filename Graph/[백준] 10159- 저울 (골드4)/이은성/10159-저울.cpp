#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    int a, b;
    int count;
    bool hchecked[100];
    bool lchecked[100];
    vector<vector<int> > heavier(n);                   //heavier[a] a보다 무거운 애들 벡터
    vector<vector<int> > lighter(n);                   //lighter[a] a보다 가벼운 애들 벡터
    queue<int> q;


    for(int i = 0 ; i < m; i++){
        cin >> a >> b;
        lighter[a - 1].push_back(b - 1);
        heavier[b - 1].push_back(a - 1);
    }

    for(int i = 0; i < n; i++){
        memset(hchecked, false, sizeof(hchecked));
        memset(lchecked, false, sizeof(lchecked));
        count = 0;
        q.push(i);
        lchecked[i] = true;
        while(!q.empty()){                              //본인보다 가벼운 것들 서칭
            for(int j = 0; j < lighter[q.front()].size(); j++){
                if(lchecked[lighter[q.front()][j]] == false){
                    q.push(lighter[q.front()][j]);
                    lchecked[lighter[q.front()][j]] = true;
                }
            }
            q.pop();
        }
        q.push(i);
        hchecked[i] = true;
        while(!q.empty()){                              //본인보다 무거운 것들 서칭
            for(int j = 0; j < heavier[q.front()].size(); j++){
                if(hchecked[heavier[q.front()][j]] == false){
                    q.push(heavier[q.front()][j]);
                    hchecked[heavier[q.front()][j]] = true;
                }
            }
            q.pop();
        }

        for(int j = 0; j < n; j++){
            if(!hchecked[j] && !lchecked[j])
                count++;
        }
        cout << count << '\n';
    }

    return 0;
}
