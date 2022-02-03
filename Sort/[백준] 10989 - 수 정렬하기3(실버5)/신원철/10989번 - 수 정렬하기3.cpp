#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n; 
    cin >> n;
    
    int dp[10001] = {0,};
    
    int number = 0;
    for(int i = 0; i < n; i++){
        cin >> number;
        dp[number] ++;
    }
    for(int i = 1; i<=10000; i++){
        if (dp[i] > 0){
            for(int j = 0; j < dp[i]; j++){
                cout << i << "\n";
            }
        }
    }
    
    return 0;
}