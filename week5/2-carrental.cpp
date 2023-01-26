#include<iostream>
#include<vector>
using namespace std;

int k, n;
int i, j;
int c, p, w ;
int matrix[101][3] ; 
int weigth[1001] ; 
int minVal = 0xfffffff ;

//have no bug
void readInput() {
    cin >> k >> n;
    for (i=0;i<k;i++) {
        cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] ;
    }
    for (i=0;i<n;i++) {
        cin >> weigth[i] ;
    }
}

int minContract(int index) {
    // int count = 1 ;
    int sum = 0 ;
    int i ;

    c = matrix[index][0];
    p = matrix[index][1];
    w = matrix[index][2];
    
    int cost = c + p ; 

    for (i=0;i<n;i++) {
        if (weigth[i] > w) {
            return -1 ;
        }
        sum += weigth[i] ; 
        if (sum > w) {
            // count++ ;
            cost += p ;
            sum = weigth[i] ; 
        }
    }
    return cost ; 

}

int eachContract() {
    int i ;
    for (i=0; i<k ;i++) {
        int val = minContract(i) ; 
        if (val < minVal && val != -1) {
            minVal = val ;
        }
    }
    return minVal ;
}
int main() {
    readInput() ;
    cout << eachContract() ; 
}