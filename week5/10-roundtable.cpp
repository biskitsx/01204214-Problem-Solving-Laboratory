#include<iostream>
#include<unordered_map>
using namespace std;

int n, i;
int order[200001] ; 
int maxCount = 0; 

unordered_map<int,int> moveCount ; 

void readInput() {
    cin >> n ;
    for (i=1;i<=n;i++) {
        cin >> order[i] ;
    }
}

int maxTable() {
    for (i=1;i<=n;i++) {
        int move = (order[i] - i + n)%n;
        moveCount[move]++ ;
        maxCount = max(maxCount,moveCount[move]); 
    }
    return maxCount ;
}

int main() {
    readInput() ;
    cout << maxTable() ;
}