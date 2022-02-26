#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> VI;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    VI v(n + 1);
    VI dp(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> v[i];
    

    v[0] = 0;
    dp[0] = 0;
    dp[1] = v[1];
    dp[2] = v[1] + v[2];

    for(int i = 3; i <= n; i++){
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }

    cout << dp[n];
    return 0;;
}
