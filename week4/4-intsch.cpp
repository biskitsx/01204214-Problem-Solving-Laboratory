#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n, s, t ;
int i ;
int countEach = 0 ;
int endTime = 0 ;
vector <pair <int,int> > interval ; 

void readInput(){ 
    cin >> n; 
    for (i=0;i<n;i++) {
        cin >> s >> t; 
        interval.push_back(make_pair(t,s)) ; 
    }
    sort(interval.begin(),interval.end()) ; 
}

int findSchedule() {
    for (i=0;i<n;i++) { 
        if (endTime <= interval[i].second) {
            endTime = interval[i].first ; 
            countEach++ ;
        }   
    }
    return countEach ; 
}

int main() {
    readInput();
    cout << findSchedule();
}