/*
    인덱스로 순열을 만들어 각 순열에 대한 수식을 완전탐색으로 비교
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, input, max = 0, sum;
    vector<int> v1;                  //  입력받은 값 배열

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> input;
        v1.push_back(input);
    }

    sort(v1.begin(), v1.end());
    
    do{
        sum = 0;
        for(int i = 0; i + 1 < n ; i++)
            sum += abs(v1[i] - v1[i + 1]); 
        max = max > sum ? max : sum;

    }while(next_permutation(v1.begin(), v1.end()));
    
    cout << max;

    return 0;
}
