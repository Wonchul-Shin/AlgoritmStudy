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
    list<string> chain = {};    // 몇가지 항목이 있는지 담을 리스트
    list<string>::iterator iter = chain.begin();
        
    for (i = 0; i < n; i++){
        answer = 1;
        chain = {};
        cin >> num;

        for (j = 0; j < num; j++){
            cin >> word1 >> word2;

            if (hash.find(word2) == hash.end()){ // 해당 항목이 존재하지 않으면
                hash[word2] = 1; // 키값을 1로 설정
                chain.push_back(word2); // 리스트에도 추가 
            }
            
            else{ // 항목이 존재하면 key값을 +1
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
