#include "probelib.h"
#include <cstdio>
#include <iostream>
int n;
using namespace std ;

int findProbe(int left,int right) {
    // cout << left << ' ' << right << endl ; 
    
    if (left == right) {
        return left ;
    }

    int mid = (right+left)/2 ; 

    //treasure on the left side
    if (probe_check(left,mid)) {
        return findProbe(left,mid) ; 
    }
    //treasure on the right side
    else {
        return findProbe(mid+1,right) ; 
    }
}

int main(){
    int n = probe_init();

    int x = findProbe(0,n-1) ; 
    // cout << "answer is " << x << endl ;
    probe_answer(x) ; 
}