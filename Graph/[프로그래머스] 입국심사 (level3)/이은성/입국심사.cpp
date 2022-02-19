#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left, right, mid;
    long long tmp;
    sort(times.begin(), times.end());

    left = 1LL;
    right = (long long)times.back() * n;
    mid = (left + right) / 2;

    while(1){
        if(right - left == 1)
            return mid + 1;
            
        tmp = 0;
        for(int i = 0; i < times.size(); i++){
            tmp += mid / times[i];
        }

        if(tmp >= n){
            right = mid;
            mid = (left + right) / 2;
        }
        else if(tmp < n){
            left = mid;
            mid = (left + right) / 2;
        }
    }
}

int main(){

    int n = 6;
    vector<int> times;

    times.push_back(7);
    times.push_back(10);

    cout << solution(n, times);

    return 0;
}
