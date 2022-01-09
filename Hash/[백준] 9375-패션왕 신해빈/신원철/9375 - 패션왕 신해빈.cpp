#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;

int main()
{
    unordered_map<string, int> hash;
    int n, i, j;
    int num;
    string word1, word2;
    int answer = 1;
    cin >> n;
    list<string> chain = {};    
    list<string>::iterator iter = chain.begin();
        
    for (i = 0; i < n; i++){
        answer = 1;
        chain = {};
        cin >> num;

        for (j = 0; j < num; j++){
            cin >> word1 >> word2;

            if (hash.find(word2) == hash.end()){
                hash[word2] = 1;
                chain.push_back(word2);
            }
            
            else{
                hash[word2] ++;

            }
        }
        
        for (iter=chain.begin(); iter != chain.end(); iter++){
            answer *= (hash[*iter] + 1);
        }

        if (num == 0){
            cout << 0 << endl;
        }
        else{
            cout << answer - 1 << endl;
        }

        hash.clear();
    }
    
    return 0;
}