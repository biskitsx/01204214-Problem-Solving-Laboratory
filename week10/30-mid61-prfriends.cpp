// #include <iostream>
// using namespace std ;

// int l, r ;
// bool isPrime(int num) {
//     if (num < 2) {
//         return false;
//     }
//     for (int i = 2; i <= num / 2; ++i) {
//         if (num % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// int printPrimes() {
//     int prev = 2 ;
//     int countt = 0 ;

//     if (l < 2) {
//         l = 2 ;
//     }
//     for (int i = l; i <= r; ++i) {
//         if (isPrime(i)) {
//             if (i - prev == 2) {
//                 // cout << i << ' ' << prev << endl;
//                 countt++ ;
//             }
//             prev = i ; 
//         }
//     }
//     return countt ;
// }

// int main() {
//     cin >> l >> r ;
//     cout << printPrimes();
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int l, r;

int printPrimes() {
    int countt = 0;
    vector<bool> isPrime(r + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= r; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= r; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int prev = -1;
    for (int i = l; i <= r; ++i) {
        if (isPrime[i]) {
            if (prev != -1 && i - prev == 2) {
                // cout << i << ' ' << prev << endl;
                countt++;
            }
            prev = i;
        }
    }
    return countt;
}

int main() {
    cin >> l >> r;
    cout << printPrimes();
    return 0;
}
