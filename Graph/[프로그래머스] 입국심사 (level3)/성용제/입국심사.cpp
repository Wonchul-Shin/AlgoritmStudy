#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    int l = times.size();
    sort(times.begin(),times.end()); // 오름차순으로 정렬

    long long start = (long long)times[0]; // 
    long long end = (long long)times[l-1] * n; // n 명이 모두 가장 긴 시간을 소요한 최악의 경우
    long long mid;
    // 1~end 범위에서 이분 탐색
    while(start < end)
    {
        mid = (start+end)/2; // 중간값
        long long cnt = 0;
        
        for(int i=0;i<l;i++) cnt+=mid/times[i]; // 중간값을 모든 값으로 나눈 몫을 더해준다.
        if(cnt >= n) end = mid; // 몫의 합이 n 보다 크거나 같으면 end 값 갱신
        else start = mid + 1; // 몫의 합이 n 보다 작으면 start 값 갱신
    }

    return start; // 마지막으로 변경된 start 값이 
}

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);

    int n; cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a; cin>>a;
        arr.push_back(a);
    }
    cout<<solution(n,arr)<<'\n';
}