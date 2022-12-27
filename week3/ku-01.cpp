#include<iostream>

using namespace std;

int main() {

    int l ,n ,i, j;
    int a, b, max = 0 ;   
    int bridge[100000] = {0} ; 

    cin >> l >> n  ;

    for (i=0;i<n;i++) {
        
        cin >> a >> b ;

        b = b*3 - 1; 
        a = a*3 ; 

        for (j=a;j<=b;j++) {

            bridge[j]++ ;

            if (bridge[j] > max) {
                max = bridge[j] ; 
            }

            else {
                
            }

        }
    
    }
    cout << max ; 
}