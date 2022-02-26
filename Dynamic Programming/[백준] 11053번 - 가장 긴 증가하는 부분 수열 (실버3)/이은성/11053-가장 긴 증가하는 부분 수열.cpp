#include <iostream>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int arr[1000];
    int lis[1000]{0, };
    int n; cin >> n;
    int index, count;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    lis[0] = 1;
    for(int i = 1; i < n; i++){
        index = 0;
        count = 0;
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j] && count < lis[j]){
                count = lis[j];
            }
        }
        lis[i] = count + 1;
    }

    count = 0;

    for(int i = 0; i < n; i++){
        if(count < lis[i])
            count = lis[i];     
    }

    cout << count;
    return 0;
}
