#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n;
    int a;
    int input;
    priority_queue<int> present;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;

        if(a == 0){
            if(present.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << present.top() << '\n';
                present.pop();
            }
        }

        for(int j = 0; j < a; j++){
            cin >> input;
            present.push(input);
        }
    }

    return 0;
}
