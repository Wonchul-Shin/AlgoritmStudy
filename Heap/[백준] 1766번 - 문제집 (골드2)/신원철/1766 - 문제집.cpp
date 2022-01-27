#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<int, priority_queue<int, vector<int>, greater<int>>> hash_container;

void search(unordered_map<int, priority_queue<int, vector<int>, greater<int>>> &hash_container, int num){
    if(hash_container[num].empty()){ // 만약 이미 출력된 번호라면
        
    }
    else{ // 출력되지 않았다면
        priority_queue<int, vector<int>, greater<int>> temp_que = {};
        temp_que = hash_container[num];
        int temp = temp_que.top(); // 맨앞의 값 확인 
        if(temp = -1){ // 맨앞이 -1이라면 관계가 있을 수도 있고 없을 수도 있다.  
            hash_container[num].pop();
            if(hash_container[num].empty()){ // 만약 -1 다음 값이 없다면 관계가 없다는 뜻이다. 
                cout << num << " "; // 해당 문제 출력
            }
            else{ // -1 다음 값이 있다면 우선순위이므로 출력해줘야 한다. 
                int que_len = hash_container[num].size();
                for (int j = 0; j < que_len; j++){
                    priority_queue<int, vector<int>, greater<int>> temp_que = {};
                    temp_que = hash_container[num];
                    temp = temp_que.top(); // 맨앞의 값 확인
                    search(hash_container, temp);
                    hash_container[num].pop();
                }
                cout << num << " ";
                
            }
        }
        
        else{
            
            int que_len = hash_container[num].size();
            for (int j = 0; j < que_len; j++){
                priority_queue<int, vector<int>, greater<int>> temp_que = {};
                temp_que = hash_container[num];
                temp = temp_que.top(); // 맨앞의 값 확인
                search(hash_container, temp);
                hash_container[num].pop();
            }
            cout << temp << " ";
        }
        
    }
    
    
    
}



int main()
{
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, m, temp1, temp2;
    int count = 0;
    cin >> n >> m;
    
    
    
    for (int i = 1; i <= n; i++){
        hash_container[i] = {};
        hash_container[i].push(-1);
        
    }
    
    for(int i = 0; i < m; i++){
        cin >> temp1 >> temp2;
        hash_container[temp2].push(temp1);
    }
    
    for(int i = 1; i <= n; i++){
        search(hash_container, i);
    }
    
    return 0;
}