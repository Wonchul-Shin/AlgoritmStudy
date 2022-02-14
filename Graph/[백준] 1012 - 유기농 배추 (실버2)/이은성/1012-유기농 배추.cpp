#include <iostream>

using namespace std;

void bug(int **arr1, int **arr2, int i, int j, int &m, int &n){
    
    arr2[j][i] = 1;
    if( i > 0 && arr1[j][i - 1] == 1 && arr2[j][i - 1] == 0)
        bug(arr1, arr2, i - 1, j, m, n);
    if( j > 0 && arr1[j - 1][i] == 1 && arr2[j - 1][i] == 0)
        bug(arr1, arr2, i, j - 1, m, n);
    if( i + 1 < m && arr1[j][i + 1] == 1 && arr2[j][i + 1] == 0)
        bug(arr1, arr2, i + 1, j, m, n);
    if( j + 1 < n && arr1[j + 1][i] == 1 && arr2[j + 1][i] == 0)
        bug(arr1, arr2, i, j + 1, m, n);
}

int main(){

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int t, m ,n, k, count;
    int **arr1;
    int **arr2;
    int x, y;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> m >> n >> k;

        count = 0;

        arr1 = new int*[n];
        arr2 = new int*[n];

        for(int j = 0; j < n; j++){
            arr1[j] = new int[m]{0,};
            arr2[j] = new int[m]{0,};
        }
        for(int j = 0; j < k; j++){
            cin >> x >> y;
            arr1[y][x] = 1;
        }

        for(int j = 0; j < n; j++){
            for(int l = 0; l < m; l++){
                if(arr1[j][l] == 1 && arr2[j][l] == 0){
                    bug(arr1, arr2, l, j, m, n);
                    count++;
                }
            }
        }

        cout << count << '\n';
        delete[] arr1;
        delete[] arr2;
    }

    return 0;
}
