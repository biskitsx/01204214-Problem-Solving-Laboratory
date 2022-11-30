#include<iostream>
#include<vector>
using namespace std ;

vector<int> decodeYtoX(vector<int> vectNums, int n ) {
    vector <int> vectX ;
    int i ;
    if (vectNums[0] < n) {
        vectX.push_back(0) ;
    }
    else {
        vectX.push_back(1) ; 
    }
    for (i=1;i<n;i++) {
        if (vectNums[i] > vectNums[i-1]) {
            vectX.push_back(1) ;
        }
        else {
            vectX.push_back(0) ;
        }
    }
    return vectX ;
}

vector<int> decodeZtoY(vector<int> vectNums,int n) {
    vector<int> vectY ; 
    int i ;

    //init vect Y with two index 
    vectY.push_back(vectNums[0]) ; 
    for (i=1;i<n;i++) {
        
        int prev = vectY[i-1];
        int min = prev-1;
        int max = prev+1;

        if (min+prev == vectNums[i]|| min+prev*2 == vectNums[i]) {
            vectY.push_back(min) ; 
        }
        else {
            vectY.push_back(max) ; 
        }
    }
    return vectY ; 
}

void printVect(vector<int> vect,int n) {
    int i ; 
    for (i=0;i<n;i++) {
        cout << vect[i] << endl; 
    }
}
int main() {
    int i,n,t,num ;
    vector<int> vectNum ;    
    
    //input and keep data on vectNum 
    cin >> n >> t ;
    for (i=0;i<n;i++) {
        cin >> num ; 
        vectNum.push_back(num) ; 
    }

    //Z to Y 
    if (t==2) {
        vectNum = decodeZtoY(vectNum,n) ; 
    }

    //Y to X 
    vectNum = decodeYtoX(vectNum,n) ; 
    printVect(vectNum,n) ; 
}