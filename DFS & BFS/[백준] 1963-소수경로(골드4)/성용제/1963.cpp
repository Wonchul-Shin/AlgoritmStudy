#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <string.h>

using namespace std;

int T;
bool prime_num[10000]; // 소수는 true
bool visit[10000]; //
int num1,num2; 

// 에라토스테네스의 체를 이용하여 소수 구하기
void Eratosthenes()
{
    memset(prime_num,true,sizeof(prime_num));
    for(int i=2;i<=sqrt(9999);i++)
    {
        if(prime_num[i] == false) continue;
        for(int j=i+i;j<=9999;j+=i)
        {
            prime_num[j] = false;
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    cin>>T;

    Eratosthenes();

    for(int i=0;i<T;i++)
    {
        memset(visit,false,sizeof(visit));
        int ans = 0;
        bool find_num = false;
        cin>>num1>>num2;

        queue<pair<int,int>> q;
        q.push({num1,0});
        visit[num1] = true;
        // BFS 돌려서 한 자리씩 변경해가며 정답을 맞출 수 있는지 확인
        while(!q.empty()){
            int now = q.front().first;
            int now_num = q.front().second;
            q.pop();

            if(now == num2){
                ans = now_num;
                find_num = true;
                break;
            }

            for(int i=0;i<4;i++)
            {
                int next_num;
                for(int j=0;j<10;j++)
                {
                    string s = to_string(now);
                    s[i] = (j + '0');
                    next_num = stoi(s);
                    if(prime_num[next_num]==false) continue;
                    if(visit[next_num]==true) continue;
                    if(next_num>=10000 || next_num <1000) continue;

                    visit[next_num] = true;
                    q.push({next_num,now_num+1});
                }
            }
        }
        if(find_num) cout<<ans<<'\n';
        else cout<<"Impossible\n";
    }
}