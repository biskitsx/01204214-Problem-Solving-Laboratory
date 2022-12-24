#include <iostream>
#include <list>
using namespace std ;

void showText(list<char> res) {
    list<char>::iterator p ;
    for (p=res.begin();p!=res.end();p++) {
        cout << *p ;
    }
    cout << '\n' ; 
}

int main() {
    
    string text ; 
    // text = "This_is_a_[Beiju]_text" ;
    // cout << text.size() ;
    while (getline(cin,text)) {
        int i ;
        list <char> res ;
        list <char> :: iterator pos = res.end();  
        for (i=0;i<text.size();i++) {
            char alphaBet = text[i] ;
            if (alphaBet=='[') {
                pos = res.begin() ; 
            }
            else if (alphaBet==']') {
                pos = res.end() ; 
            }

            else {
                res.insert(pos,alphaBet)  ;
            }
        }
        showText(res) ; 
    }

}