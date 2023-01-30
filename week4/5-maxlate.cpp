#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n ;
int d, c;
int i, j;
int currentDate = 0 ;
int pay = 0 ;

vector <pair<int,int> > interval ; 

void readInput() {
    cin >> n ;
    for (i=0;i<n;i++) {
        cin >> d >> c; 
        interval.push_back(make_pair(d,c)) ;
    }
    sort(interval.begin(),interval.end()) ;
}

int greedy() {
    for (auto job :  interval) {
        int deadLine = job.first ;
        int jobDuration = job.second ; 

        currentDate += jobDuration ;
        
        if (deadLine+10 < currentDate) {
            pay = max(((currentDate - deadLine - 10)*(1000)),pay); 
            // cout << pay << endl ;
        }
    }
    return pay ;
}

int main() {
    readInput() ;
    cout << greedy() ; 
}