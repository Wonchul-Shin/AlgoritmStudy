#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>

using namespace std;


int main()
{
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, temp, temp1, temp2, temp3;
    
    
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
    
    cin >> n;
    
    
    cin >> temp;
    cout << temp << "\n";
    
    if(n == 1){
        return 0;
    }
    
    
    cin >> temp1;
    
    if (temp > temp1){
        cout << temp1 << "\n";
        small.push(temp1);
        big.push(temp);
    }
    else{
        cout << temp << "\n";
        small.push(temp);
        big.push(temp1);
    }
    int small_len = 0;

    for (int i = 2; i < n; i++){
        
        
        cin >> temp; 
        
        temp1 = small.top(); // small 가방 위에 있는 값
        temp2 = big.top(); 

        if (temp1 >= temp){ // 새로 들어온 값이 small의 최대값보다 작거나 같다면  
            
            
            if(small_len == 1){ // 현재 small에 더 많은 값이 들어있다면, 
                small.pop();
                small.push(temp); // temp를 small에 넣고
                big.push(temp1); // small 맨 위에 있던 값을 big에 넣는다. 
                small_len = 0; 
            }
            
            else{ // big과 small이 동일한 수의 값을 가지고 있다면
                small.push(temp); // temp값을 small에
                small_len = 1;
            }
        } 
        
        else{ // 새로 들어온 값이 small의 최대값보다 크다면 - big에 속한다면 
            if(small_len == 1){ // 현재 small이 big보다 하나가 많다면 
                big.push(temp); // big에 temp값을 넣음
                small_len = 0;
            }
            
            else{ // 현재 small과 big의 개수가 같다면
                temp2 = big.top(); 
                if (temp2 >= temp){ // big의 최솟값이 temp보다 크다면 
                    small.push(temp); // temp값을 small에 넣음
                    small_len = 1; // small이 1 더 많음
                }
                else{ // temp가 big의 최솟값 보다 크다면 
                    big.pop(); // big의 최솟값을 뽑고 
                    big.push(temp); 
                    small.push(temp2); // big의 최솟값을 small에 넣는다
                    small_len = 1;
                }
                
            }
        }
        temp3 = small.top();
        cout << temp3 << "\n";
    }
    
    
   
}