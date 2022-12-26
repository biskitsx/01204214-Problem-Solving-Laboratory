#include<iostream>
#include<vector>
using namespace std ; 

class Node {
public:
    int data;
    Node* next;
    // Default constructor
    Node(){
        data = 0;
        next = NULL;
    }
    // Parameterised Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
} ;


Node *findAddress(Node *root,int value) {
    Node *p = root ;
    while(1) {
        if (p==nullptr || p->data == value) {
            return p ;
        }
        p=p->next ; 
    }
    return nullptr ;
}

Node *isHave(vector<Node*> beadLine,int value) { 
    vector <Node*> ::iterator p ;
    Node * ptrNode ;
    for (p=beadLine.begin();p!=beadLine.end();p++) {
        ptrNode = findAddress(*p,value) ;
        if (ptrNode !=nullptr) {
            return ptrNode ;
        }
    }
    return nullptr ; 
}

vector<Node*> popVect(vector<Node*> beadLine,int value) { 
    vector <Node*> ::iterator p ;
    Node * ptrNode ;
    int i = 0 ;
    for (p=beadLine.begin();p!=beadLine.end();p++) {
        ptrNode = findAddress(*p,value) ;
        if (ptrNode !=nullptr) {
            break; 
        }
        i++ ;
    }
    
    p = beadLine.begin() ; 
    advance(p,i) ; 
    beadLine.erase(p) ; 

    return beadLine ; 
}

void showList(Node *beadLine) {
    Node *p = beadLine ;
    while(1) {
        if (p->next == nullptr) {
            cout <<p->data << '\n'; 
            break;
        }
        cout << p->data << ' ' ; 
        p=p->next ; 
    }
}

int main() {
    int n,i ,begin,next;

    cin >> n ;
    vector <Node*> beadLine ; 

    for (i=0;i<n-1;++i) {
        cin >> next >>  begin; 

        Node *beginBead = isHave(beadLine,begin) ;
        Node *nextBead = isHave(beadLine,next) ; 

        //case 1 beginBead is not used
        if (beginBead==nullptr) {
            //create Begin
            Node *beginBead = new Node(begin) ;

            //next Bead is not used  
            if (nextBead==nullptr) {
                beginBead->next = new Node(next) ; 
            }
            //next Bead is used
            else {
                beadLine = popVect(beadLine,next); 
                beginBead->next = nextBead ; 
            }
            beadLine.push_back(beginBead) ; 
        }

        //case 2 beginBead is used
        else {
            Node *afterBead = beginBead->next ; 
            
            //next Bead is not used 
            if (nextBead == nullptr) {
                beginBead->next = new Node(next) ; 
            }

            //next Bead is used 
            else {
                beadLine = popVect(beadLine,next) ; 
                
                Node *p = nextBead ; 
                while (p->next!=nullptr) {
                    p = p->next ; 
                }
                
                beginBead->next = nextBead ; 
                p->next = afterBead ; 
                

            }

        }
    }

    showList(beadLine[1]) ; 


}