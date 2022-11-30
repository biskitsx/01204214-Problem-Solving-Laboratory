#include<iostream>
using namespace std ;

int main() {
    string command ;
    cin >> command ; 
    int x = 0 , y = 0 ,i;
    for (i=0;i< command.size();i++) {
        if (command[i]=='N') y++ ;
        else if (command[i]=='S') y-- ;
        else if (command[i]=='E') x++ ;
        else if (command[i]=='W') x-- ;
        else {
            x=0;
            y=0;
        }
    }
    cout << x << " " << y ;

}