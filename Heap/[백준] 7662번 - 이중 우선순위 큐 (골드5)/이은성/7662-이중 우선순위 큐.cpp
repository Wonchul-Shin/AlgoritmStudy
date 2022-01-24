#include <iostream>
#include <set>

using namespace std;

int main(){

    int t, k, n;
    char c;
    multiset<int> ms;
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> t;

    for(int i = 0; i < t; i ++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> c >> n;

            if(c == 'I'){
                ms.insert(n);
                
            }

            else if(c == 'D'){
                if(ms.empty()){

                }
                else if(n == 1){
                    ms.erase( --ms.end());
                }

                else if(n == -1){
                    ms.erase (ms.begin());
                }
            }

        }
        
        if(ms.empty())
            cout << "EMPTY" << '\n';
        
        else
            cout<< *ms.rbegin() << ' ' << *ms.begin() << '\n';
        
        ms.clear();

    }

    return 0;
}
