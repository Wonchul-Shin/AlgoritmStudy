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
    
    vector<int> ball_list; // 공들의 색들을 담는 배열 
    unordered_map <int, multiset<int>> table; // 첫번째는 색, multiset에는 무게 순서대로
    vector<int> dp(2001, 0); // 해당 무게까지의 총 무게합을 구해주는 배열 
    int temp = 0;
    
    
    for(int i = 0; i < n; i++){// 배열을 채워주는 loop
        cin >> color >> size;
        table[color].insert(size); // 해당 색에 multiset에 추가 
        ball_list.push_back(color); 
        ball_list.push_back(size);
        dp[size] += size;
    }
    
    for(int i = 1; i < 2001; i++){ // 무게를 계산해주는 loop
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
        answer = dp[size - 1]; // 그 이전 사이즈까지의 합
        multiset<int> temp2 = table[color]; 
        for(auto k : temp2){ // 같은 볼의 색은 빼주어야 한다. 
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
