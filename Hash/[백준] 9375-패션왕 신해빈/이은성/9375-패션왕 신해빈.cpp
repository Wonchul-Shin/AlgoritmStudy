#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int n1, n2, result;
    string name, group;
    unordered_map<string, int> *m;

    cin >> n1;
    m = new unordered_map<string, int>[n1];

    for(int i = 0; i < n1; i++){

        cin >> n2;
        result = 1;
        for(int j = 0; j < n2; j++){
            cin >> name >> group;
            
            if(m[i].find(group) != m[i].end())
                m[i][group]++;
            else
                m[i][group] = 1;
        }

        for (auto j = m[i].begin() ; j != m[i].end() ; j++)
            result *= (j->second) + 1;

        result -= 1;

        cout << result << '\n';
    }
    
    delete m;

    return 0;
}
