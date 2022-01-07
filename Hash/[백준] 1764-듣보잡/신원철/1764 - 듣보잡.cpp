#include <iostream>
#include <unordered_map>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int answer = 0;
    
    unordered_map<string, int> hash;
    string word;
    for(int i = 0; i < n; i++){
        
        cin >> word;
        hash[word] = 1;
    }
    for (int i = 0; i < m; i++){
        cin >> word;
        if (hash[word] == 1){
            answer ++;
        }
    }
    
    
    cout<<answer;

    return 0;
}