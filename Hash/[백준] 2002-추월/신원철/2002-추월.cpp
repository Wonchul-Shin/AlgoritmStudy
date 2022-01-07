#include <iostream>
#include <unordered_map>
#include<list>

using namespace std;
int main()
{
    int n;
    int answer = 0;
    cin >> n;
    

    unordered_map<string, int> hash;
    
    list<int> chain;
    
    list<int>::iterator iter = chain.begin();



    string word;

    for(int i = 0; i < n; i++){
        cin >> word;
        hash[word] = i;
        chain.push_back(i);
    }
    iter = chain.begin();
    for(int i = 0; i < n; i++){
        cin >> word;
        iter = chain.begin();

        if (hash[word] == *iter){
            chain.pop_front();

        }
        else{
            for(iter=chain.begin(); iter != chain.end(); iter++){
                if(hash[word] == *iter){
                    chain.erase(iter);
                    answer++;
                    break;
                }
            }
        }
    }

    cout << answer;


    return 0;
}

