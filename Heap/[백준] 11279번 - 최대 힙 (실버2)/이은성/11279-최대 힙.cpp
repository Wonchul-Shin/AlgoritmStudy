#include <iostream>
#include <queue>

using namespace std;

int main(){
    
    int n;
    int input;
    priority_queue<int> pq;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i ++){
        cin >> input;

        if(input == 0){
            if(pq.empty())
                cout << 0 << '\n';
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else{
            pq.push(input);
        }
        
    }

    return 0;

}
