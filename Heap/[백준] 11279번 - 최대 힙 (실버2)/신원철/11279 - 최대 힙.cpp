#include <iostream>
#include <queue>
using namespace std;

int main()
{
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, temp;
    priority_queue<int> que;
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> temp;
        if (temp == 0){
            if(!que.empty()){
                temp = que.top();
                que.pop();
                cout << temp << "\n";
            }
         
            else{
                cout << 0 << "\n";
            }
        }
        
        else{
            que.push(temp);
        }
    }
    
    return 0;
}