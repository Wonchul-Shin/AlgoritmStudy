#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> vec;
    int n, temp, curr;
    int answer = 0;
    cin >> n;
    
    
    for (int i = 0; i < n; i++){
        
        cin >> temp;
        vec.push_back(temp);
    }

    for (int i = 0; i < n; i++){
        curr = vec[i]; // 현재 위치를 저장        
        for (int j = i + 1; j < n; j++){
            if (j == i + 1){ // 첫번째 일때 (무조건 보임)
                answer++;
                if(vec[j] > curr){ // 만약 두번째가 첫번째 보다 크다면 
                    break; // 그 다음부터는 못봄
                }
                else{
                    temp = vec[j]; // temp값에 두번째 값을 저장 
                }
            }
            else{ // 두번째 이상일 때 
                if(vec[j] >= temp){ // 만약 내가보려고하는 위치가 중간에서 가장 큰값보다 크다면
                    answer++;
                    temp = vec[j]; // 볼 수 있었다는건 curr과 vec[j]에 두 값보다 큰 값이 없었다는 뜻 
                }

                
            }
        }
    }
    
    cout << answer;
}