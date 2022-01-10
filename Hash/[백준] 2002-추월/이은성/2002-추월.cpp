#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int n, *arr, index, count = 0;
    string s;
    unordered_map<string, int> m;

    cin >> n;
    arr = new int[n];                                      // n개 입력받고 int형배열동적 할당
    
    for(int i = 0; i < n; i++){                            // 터널 들어간 순서 입력 
        cin >> s;
        m[s] = i;
    }

    for(int i = 0; i < n; i++){                             // 나온 순서 입력
        cin >> s;
        arr[i] = m[s];
    }

    index = 0;

    for(int i = 0 ; i < n; i++){                            // 앞서간 차량 찾기
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
