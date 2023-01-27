#include<iostream>
#include<vector>
using namespace std;

int n, i;
int order[200001] ; 
int lastMax = 0 ;
int currMax = 1 ;

void readInput() {
    cin >> n ;
    for (i=0;i<n;i++) {
        cin >> order[i] ;
    }
}

void maxSort() {
    for (i=0;i<n-1;i++) {
        if (order[i]+1 == order[i+1] || (order[i] == n && order[i+1] == 1)) {
            currMax++ ;
            // cout << currMax << endl;
        }
        else {
            if (lastMax < currMax) {
                lastMax = currMax ;
            }
            currMax = 1 ;
        }
    }
}

int main() {
    readInput() ;
    maxSort() ; 
    // cout << "lastmax = " << lastMax << " currMax = " << currMax << endl;
    if (currMax > lastMax) {
        cout << currMax ;
    }
    else {
        cout << lastMax ; 
    }
}