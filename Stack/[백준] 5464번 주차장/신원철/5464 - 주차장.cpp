#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, array<int,2>> parking;
    unordered_map<int, array<int,2>> car;

    queue<int> que;

    int answer = 0;
    int n,m, temp, temp2;
    
    
    cin >> n >> m;
    int left = n; // 주차장이 얼마나 남았는지 
    
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        parking[i] = {0, temp}; // 주차장 현재 상태와 무게당 비용
    }
    
    for (int i = 1; i <= m; i++){
        cin >> temp;
        car[i] = {-1, temp}; // 어느 주차장에 주차되었는지와 차의 무게  
    }
    
    
    
    for(int i = 0; i < m*2; i++){
        cin >> temp;
        
        if(temp > 0){
            if(left == 0){
                que.push(temp);
            }
            
            else{ // 만약 가득 차있지 않다면 
                for(int j = 0; j < n; j++){

                    if(parking[j][0] == 0){
                        parking[j][0] = 1;
                        answer += parking[j][1] * car[temp][1];
                        car[temp][0] = j; // 어떤 주차장에 주차했는지 기록
                        left --;
                        break;
                    }
                }
            }
        }
        
        else{ // 차를 빼는 상황이면 
            temp = -temp;
            int parkinglot = car[temp][0];
            parking[parkinglot][0] = 0; // 차를 빼고
            if (que.empty() == 0){ // 대기열이 비어있지 않다면
                temp2 = que.front(); // temp2에다가 주차할 차를 주차 
                que.pop();
                
                 for(int j = 0; j < n; j++){ // 주차장을 돌면서 
                    if(parking[j][0] == 0){ // 주차가 안된 곳을 찾아서 
                        parking[j][0] = 1; // 주차상태로 만들고 
                        answer += parking[j][1] * car[temp2][1]; 
                        car[temp2][0] = j; // 어떤 주차장에 주차했는지 기록
                        break;
                    }
                }
            }
            else{ // 만약 차를 빼기만 했다면 
                left ++;
            }
        }
    
    }
    
    cout << answer;
    return 0;
}