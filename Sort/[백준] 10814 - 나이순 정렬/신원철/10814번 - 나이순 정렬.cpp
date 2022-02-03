#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    int n, age;
    string name;
    set<int> age_list;
    unordered_map <int, vector<string>> table;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        
        cin >> age >> name;
        age_list.insert(age);
        table[age].push_back(name);    
    }
    
    for(auto i : age_list){
        for (auto j : table[i]){
            cout << i << " " <<j << '\n';
        }
    }
    
    return 0;

}