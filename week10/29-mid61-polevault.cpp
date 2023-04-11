#include<iostream>
#include<vector>

using namespace std;

int n, q, x ;
vector <int> arr ;
bool check[10000001] = {false};


char can() {
    for (int i = 0 ; i < n ; i++) {
        int summ = 0;
        for (int j = i ; j <n ;j++) {
            summ += arr[j];
            if (summ == x) {
                return 'Y' ;
            }
        }
    }

    return 'N';
}
int main() {
    cin >> n >> q ;
    arr.resize(n+1);
    for (int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
    }

    for (int i =0 ;i<q;i++) {
        cin >> x;
        cout << can();
    }
}