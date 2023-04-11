#include<iostream>
using namespace std ;

int n, q ;
struct bread {
    int price ;
    int quantity ;
} ;

bread bakery[100001] ;

int findPrice(int y) {
    int minny = 0xfffff ;
    int minnyIndex  = -1 ;
    for (int i = 0 ; i<=5 ; i++) {
        if (bakery[y+i].quantity != 0) {
            if (bakery[y+i].price < minny) {
                minnyIndex = y+i ; 
                minny = bakery[y+i].price ;
            }
        }
        else if (bakery[y-i].quantity != 0) {
            if (bakery[y-i].price < minny) {
                minnyIndex = y-i ; 
                minny = bakery[y-i].price ;
            }
        }
    }
    if (minnyIndex == -1) {
        return 0 ;
    }
    //buy at minnyIndex 
    bakery[minnyIndex].quantity-- ;
    return bakery[minnyIndex].price ;
    

}

int main() {
    cout << bakery[-124].price ;

    cin >> n >> q ;
    int x, c, l, y ;

    for (int i = 0 ;i < n;i++) {
        cin >> x >> c >> l ;
        bakery[x].price = c ;
        bakery[x].quantity = l ;
    }

    for (int i =0 ; i< q;i++) {
        cin >> y ;
        cout << findPrice(y); 
    }
}