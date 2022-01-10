#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int answer = 0;
    
    unordered_map<string, int> dutdou;
    list<string> dutbow;
    list<string>::iterator iter = dutbow.begin();
    
    string word;
    for(int i = 0; i < n; i++){
        
        cin >> word;
        dutdou[word] = 1;
    }
    for (int i = n; i < n + m; i++){
        cin >> word;
        if (dutdou[word] == 1){
            dutbow.push_back(word);
        }
    }

    dutbow.sort();
    cout<< dutbow.size() << endl;
    for (iter =dutbow.begin(); iter != dutbow.end(); iter++){
        cout<<*iter << endl;
    }

    return 0;
}
