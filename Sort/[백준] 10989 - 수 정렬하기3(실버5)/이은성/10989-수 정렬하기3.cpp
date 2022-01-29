#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    int input;
    int count[10001]{0,};

    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> input;
        count[input]++;    
    }

    for(int i = 0; i <= 10000; i++){
        if(count[i] != 0){
            for(int j = 0; j < count[i]; j++){
                cout << i << '\n';
            }
        }
    }

    return 0;
}