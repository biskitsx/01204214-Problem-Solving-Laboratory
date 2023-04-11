#include<iostream>
using namespace std;

struct grader {
    int point ;
    int frequency ;
};

grader question[101] ;

int main() {
    int n, m, number, point, sumPoint =0;
    cin >> n >> m ;
    for (int i=0 ; i<m ;i++) {
        cin >> number >> point ;
        question[number].point = max(question[number].point,point);
        question[number].frequency++ ;
    }

    for (int i=1 ;i<=n;i++) {
        if (question[i].frequency > 5) {
            continue;
        }
        // cout << question[i].point << ' ';
        sumPoint += question[i].point ;
    }
    cout <<endl ;
    cout << sumPoint ;
}