#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, temp;
    vector<int> arr;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    do{
        int temp = 0;
        for(int i = 1; i < n; i++){
            temp += abs(arr[i-1] - arr[i]);
        }
        answer = max(answer, temp);
    }while(next_permutation(arr.begin(), arr.end()));

    cout << answer << "\n";
    return 0;
}
