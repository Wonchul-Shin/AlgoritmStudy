#include <iostream>
#include <queue>
using namespace std;

int main()
{
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, temp, gift;
    priority_queue<int> que;
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        if (temp == 0){
            if(!que.empty()){
                temp = que.top();
                que.pop();
                cout << temp <<  "\n";
            }
            
            else{
                cout << -1 << "\n";
            }
        }
        
        else{
            for(int j = 0; j < temp; j++){
                cin >> gift;
                que.push(gift);
            }
        }
    }
    
    return 0;
}