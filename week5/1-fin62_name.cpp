#include<iostream>
using namespace std;

string name, socialText ; 
int main() {
    int i, j,nameSize ,socialSize ,current = 0 ,s = 0;

    cin >> name ;
    cin >> socialText ;

    nameSize = name.size();
    socialSize = socialText.size() ;

    for (i=0;i<socialSize;i++) {

        if (socialText[i]==name[current]) {
            current++ ; 

            if (current == nameSize) {
                s++ ;
                current = 0 ;
            }
        }
    }
    cout << s << endl;
}