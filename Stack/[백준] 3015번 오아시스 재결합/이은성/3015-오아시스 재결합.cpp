#include <iostream>
#include <vector>

using namespace std;
int returnMin(int a, int b){
    return a < b? a : b;
}
int main(){

    int n;
    int input;
    long long count = 0;                  // 순서쌍의 수
    int max;                        // i와 j 사이의 최대값
    int min;                        // i와 j 중에 작은값
    vector<int> v;                  // 사람들이 서 있는 순서대로 input한 벡터

    cin >> n;

    for(int i = 0; i < n; i ++){                    //n개 값 입력
        cin >> input;
        v.push_back(input);
    }

    for(int i = 0; i < n; i ++){
        max = 0; 

        for(int j = i + 1; j < n; j++){             //i 와 j사이의 최대의 값을 max에 저장해서 새로운 i와 j중의 작은 값이
            min = returnMin(v[i], v[j]);            //max보다 작으면 continue 아닐 시 max를 v[j]로 바꾼 뒤 카운트 1 증가

            if(max > min)
                continue;
            
            max = v[j];
            count++;
        }
    }
    
    cout << count;
    return 0;
}
