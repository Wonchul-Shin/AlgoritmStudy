#include <iostream>
#include<queue>

using namespace std;


int main()
{
    int n, k, temp;
    queue<int> que;
    
    cin >> n >> k;
    vector<int> answer;
    
    
    for (int i = 1; i < n + 1; i++){
        que.push(i);
    }
    cout << "<";
    while(que.empty() != 1){
        
        for(int i =0; i < k -1; i++){
            que.push(que.front());
            que.pop();
        }
        
        if(que.size() == 1){
            
            cout << que.front();
            cout << ">";
            que.pop();
            
        }
        
        else{

            cout << que.front();
            cout << ", ";
            que.pop();
    
            
        }
    }
    return 0;
}
