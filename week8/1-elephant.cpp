#include<iostream>
#include<vector>
#include<algorithm>

using namespace std ;
int n ;

vector <int> score ;
vector <int> memo ; 

void readInput(){
    cin >> n ;
    score.resize(n+1) ; 
    memo.resize(n+1,-1) ;
    for (int i = 0 ; i < n ;i++) {
        cin >> score[i] ; 
    }
}

int findMax(int x,int y,int z) {
    int maxVal = x ;
    maxVal = max(maxVal,y) ;
    maxVal = max(maxVal,z) ;
    return maxVal ;
}

//use Dynamic programing คับ
int dp(int i) {
    //out of bound 
    if (i < 2 || i >= n) {
        return 0 ;
    }

    //calculated
    if (memo[i] != -1) {
        return memo[i] ; 
    }

    int case1 = score[i]+dp(i-3) ;
    int case2 = dp(i-1) ; 
    int case3 = score[i]+dp(i-4) ; 
    memo[i] = findMax(case1, case2, case3) ; 
    return memo[i] ; 
    
}

int maxScore() {
    int maxSum = 0 ;
    for (int i = 0 ; i < n;i++) {
        maxSum = max(maxSum,dp(i)) ; 
    }
    return maxSum ;
}

int main(){
    readInput() ; 
    cout << maxScore() << endl;
    for (int i = 0 ; i < n ;i ++) {
        cout << memo[i] << endl ;
    }
}