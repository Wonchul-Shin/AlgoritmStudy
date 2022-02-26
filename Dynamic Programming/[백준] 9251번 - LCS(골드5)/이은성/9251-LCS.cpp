#include <iostream>

using namespace std;

int arr[1001][1001];

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string a, b; cin >> a >> b;

    for(int i = 1; i <= a.size(); i++){
        for(int j = 1; j <= b.size(); j++){
            if(a[i - 1] == b[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else{
                arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
            }
        }
    }

    cout << arr[a.size()][b.size()];
    
    return 0;
}
