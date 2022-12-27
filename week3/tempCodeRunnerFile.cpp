#include <iostream>
#include <vector> 
using namespace std;


int main() {
    string commandLine ; 
    char command ;
    int directionState = 0 ,i , j;
    char angle[] = {'N','E','S','W'} ; 
    // 0 => N
    // 1 => E
    // 2 => S
    // 3 => W
    cin >> commandLine ;
    for (i=0;i<commandLine.size();i++) {
        command = commandLine[i] ;
        
        int countR = 0 ;

        for (j=0;j<4;j++) {
            if (command == angle[i]) {
                // cout << "bugN\n" ; 
                while (directionState != i) {
                    cout << "sad\n" ; 
                    if (directionState > 3) {
                        directionState = 0 ;
                        continue;
                    }
                    directionState++ ; 
                    countR++ ; 
                }
                break;
            }
        }
        cout << "R equal" << countR << endl ;
        if (command == 'Z') {
            directionState = 0 ;
            cout << 'Z' ; 
            continue;
        }

        if (countR != 0 )  {
            for (j=0;j<countR;j++) {
                cout << 'R' ; 
            }

        }
        cout << 'F'  ;
    }

}