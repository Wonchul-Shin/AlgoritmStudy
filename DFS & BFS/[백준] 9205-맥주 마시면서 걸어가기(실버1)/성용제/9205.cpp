#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>

using namespace std;
// 집 편의점(n개) 페스티벌장소 순으로 입력
int T;
bool visit[105];
vector<int> ans[105];
// DFS 돌려서 각각 연결된 노드들을 확인하면서 방문체크
void dfs(int n)
{
    visit[n] = true;
    for(auto it : ans[n])
    {
        if(visit[it]) continue;
        dfs(it);
    }
}
// 두 지점 사이의 거리를 계산 해주는 함수
int caldist(pair<int,int> a, pair<int,int> b)
{
    return (abs(a.first-b.first) + abs(a.second-b.second));
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin>>T;
    while(T--)
    {
        memset(visit,false,sizeof(visit));
        for(int i=0;i<105;i++) ans[i].clear();
        int n; cin>>n;

        vector<pair<int,int>> arr(n+2); // 집 + 페스티벌 + 편의점(n개) -> n+2
        for(auto& it : arr) cin>>it.first>>it.second; //전체 입력
    
        for(int i=0;i<n+2;i++)
        {
            for(int j=i+1;j<n+2;j++)
            {
                int now = caldist(arr[i],arr[j]);
                if(now <= 1000) // 맥주 20개 * 50M -> 최대 1000미터 거리내에 있으면 서로 연결
                {
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }
        dfs(0);
        if(visit[n+1]) cout<<"happy\n";
        else cout<<"sad\n";
    }
    
}