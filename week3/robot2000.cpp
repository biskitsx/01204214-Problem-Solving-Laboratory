#include <iostream>
using namespace std;

int main() {
    string commandLine ; 
    char command ;
    int directionState = 0 ,i , j;
    // 0 => N
    // 1 => E
    // 2 => S
    // 3 => W
    cin >> commandLine ;
    for (i=0;i<commandLine.size();i++) {
        command = commandLine[i] ;
        
        int countR = 0 ;

        if (command == 'N') {
            // cout << "bugN\n" ; 
            while (directionState != 0) {
                // cout << "sad\n" ; 
                if (directionState > 3) {
                    directionState = 0 ;
                    continue;
                }
                directionState++ ; 
                countR++ ; 
            }
        }

        else if (command == 'E') {
            // cout << "bugE\n" ; 

            while (directionState != 1) {
                if (directionState > 3) {
                    directionState = 0;
                    continue;
                }
                directionState++ ; 
                countR++ ; 
            }
            
        }
        else if (command == 'S') {
            // cout << "bugS\n" ; 
            while (directionState != 2) {
                if (directionState > 3) {
                    directionState = 0;
                    continue;
                }
                directionState++ ; 
                countR++ ; 
            }

        }
        
        else if (command == 'W') {
            // cout << "bugW\n" ; 

            while (directionState != 3) {
                if (directionState > 3) {
                    directionState = 0;
                    continue;
                }
                directionState++ ; 
                countR++ ; 
            }

        }
        else {
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