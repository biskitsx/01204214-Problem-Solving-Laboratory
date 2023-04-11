#include<iostream>
using namespace std ;

int n, a, b, r ;
int x, y ;

int main() {
    cin >> n >> a >> b >> r ;
    r *= r ;
    int countStudent = 0 ;
    for (int i=0;i<n;i++) {
        cin >> x >> y ;
        if (r >= (x-a)*(x-a) + (y-b)*(y-b)) {
            countStudent++ ;
        }
    }
    cout << countStudent ;
}