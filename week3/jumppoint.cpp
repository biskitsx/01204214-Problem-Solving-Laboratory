#include <iostream>
#include <vector>
#include <cmath>
#include <queue> 

using namespace std;

int n,r,i,j ;
float u,v ; 

vector <pair <float,int> > map[101] ;
pair <float,float> coor[101] ; 


pair <float,float> createPair(float u,float v) {
    pair <float,float> p ; 
    p.first = u ;
    p.second = v ;
    return p ;
}

pair <float,int>  createNode(float weight, int index) {
    pair <float,int> p ;
    p.first = weight ;
    p.second = index; 
    return p ; 
}

void readInput() {
    cin >> n >> r ;

    coor[0] = createPair(0,0) ;
    coor[n+1] = createPair(100,100) ;

    for (i=1;i<=n;i++) {
        cin >> u >> v ;
        
        coor[i] = createPair(u,v) ;

        for (j=0;j<i;j++) {
            float oldX = coor[j].first ;
            float oldY = coor[j].second ;
            
            float distance = sqrt((oldX-u)*(oldX-u)+(oldY-v)*(oldY-v)) ;

            //connect 
            if (distance <= r) {
                map[i].push_back(createNode(distance,j)) ; 
                map[j].push_back(createNode(distance,i)) ; 
            }
        }

        float distance = sqrt((100-u*1.0)*(100-u)+(100-v)*(100-v)) ;
        
        if (distance <= r) {
            map[i].push_back(createNode(distance,n+1)) ; ; 
            map[n+1].push_back(createNode(distance,i)) ; 
        }
        
    }
}


int main() {
    readInput() ;

}