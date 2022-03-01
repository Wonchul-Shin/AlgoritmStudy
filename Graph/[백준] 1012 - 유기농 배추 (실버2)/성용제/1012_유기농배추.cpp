#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

int tc,M,N,K,ans; // test_case, 가로, 세로, 개수, 정답
int arr[51][51]; 
bool V[51][51]; // 방문했는지 안했는지 확인
int d[4][2] = {
    0, 1,
    1, 0,
    0, -1,
    -1, 0
};

// 배추가 있고 방문하지 않은 곳을 기점으로 상하좌우를 확인하며 연결된 땅을 모두 방문
void DFS(int x, int y)
{
    V[x][y] = true;
    FOR(i,4)
    {
        int nx = x + d[i][0];
        int ny = y + d[i][1];

        if (nx < 0 || ny < 0 || nx >= M || ny >= N)
            continue;
        if (!V[nx][ny] && arr[nx][ny] != 0)
        {
            DFS(nx, ny);
        }
    }
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin>>tc;
    FOR(t,tc)
    {
        cin>>M>>N>>K;
        FOR(i,K){
            int a,b; cin>>a>>b;
            arr[a][b] = 1;
            V[a][b] = false;
        }
        ans = 0;
        FOR(i,M)
        {
            FOR(j,N)
            {
                // 배추가 있고 방문하지 않았다면 확인한다
                if(!V[i][j] && arr[i][j] != 0){
                    DFS(i,j);
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
