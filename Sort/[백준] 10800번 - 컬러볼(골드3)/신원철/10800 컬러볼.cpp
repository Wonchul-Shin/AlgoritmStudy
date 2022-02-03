#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, color, size, temp2;
    int answer = 0;
    cin >> n;
    
    vector<int> ball_list;
    unordered_map <int, multiset<int>> table; // 첫번째는 색, multiset에는 무게 순서대로
    vector<int> dp(2001, 0);
    int temp = 0;
    
    
    for(int i = 0; i < n; i++){
        cin >> color >> size;
        table[color].insert(size);
        ball_list.push_back(color);
        ball_list.push_back(size);
        dp[size] += size;
    }
    
    for(int i = 1; i < 2001; i++){
        if(dp[i] > 0){
            temp += dp[i];
            dp[i] = temp;
            
        }
        
        else{
            dp[i] = temp;
        }        
    }
    for(int i = 0; i < n; i++){
        answer = 0;
        color = ball_list[i * 2];
        size = ball_list[i * 2 + 1];
        answer = dp[size - 1];
        multiset<int> temp2 = table[color]; 
        for(auto k : temp2){
            if (k < size){
                answer -= k;
            }
            else{
                break;
            }
        }
        cout << answer << "\n";
    }
    
    
    return 0;
}