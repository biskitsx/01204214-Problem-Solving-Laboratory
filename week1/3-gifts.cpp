#include <iostream>
using namespace std ;

int main()
{
    int n,price ;
    int total=0 ;
    cin >> n ;
    for (int i = 0; i< n ;i++) {
        cin >> price;
        if (price>0) {
            total += price ;
        }
    }
    cout << total ;
}