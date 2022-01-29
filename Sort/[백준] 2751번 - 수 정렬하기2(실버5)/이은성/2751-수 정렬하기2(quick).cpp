/*
    제대로 작동하나 2751번의 테스트 케이스중에서 최악의 경우의 수가 들어있어서
    O( n^2 )의 속도가 나와서 시간 초과되는걸로 추정
*/

#include <iostream>

using namespace std;

void mySwap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
   
}
void mySort(int* arr, int start, int end) {

    int pivot = start;
    int i = start + 1;
    int j = end - 1;
    bool icheck, jcheck;

    if (i > j)
        return;
    while (i <= j) {
        icheck = false;
        jcheck = false;
        if (arr[i] < arr[pivot]) {
            i++;
            icheck = true;
        }
        if (arr[j] > arr[pivot]) {
            j--;
            jcheck = true;
        }
        if (!icheck && !jcheck) {
            mySwap(&arr[i], &arr[j]);
        }
    }

    mySwap(&arr[pivot], &arr[j]);
    if (j - start > 1)
        mySort(arr, start, j);
    if (end - j + 1 > 1)
        mySort(arr, j + 1, end);
}

int main() {

    int n;
    int* arr;

    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    mySort(arr, 0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}