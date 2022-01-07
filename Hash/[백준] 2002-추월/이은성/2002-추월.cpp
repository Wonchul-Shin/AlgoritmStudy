#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int n, *arr, index, count = 0;
    string s;
    unordered_map<string, int> m;

    cin >> n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> s;
        m[s] = i;
    }

    for(int i = 0; i < n; i++){
        cin >> s;
        arr[i] = m[s];
    }

    index = 0;

    for(int i = 0 ; i < n; i++){
        for(int j = index; j < n; j++){
            if(arr[j] == i){
                count += j - index ;
                index = j + 1;
                break;
            }
        }
    }

    cout << count;
    return 0;
}
