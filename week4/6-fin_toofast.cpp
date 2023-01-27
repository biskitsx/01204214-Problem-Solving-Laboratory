#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

const int INF = 0xfffffff;
int n, m, a, b, c, s;
int i, j ;

int min = -1 ;

vector<pair<int,int> > adj[1001] ; 
vector<pair<int,int> > eachAdj[1001]; 


queue <tuple <int,int,int> > expressWay ;
bool visited[1001] ;
int dist[1001] ; 

void reset() {
    int i ;
    for (i=1;i<=n;i++) {
        visited[i] = false ;
        dist[i] = INF ;
    }
}

void readInput() {
    cin >> n >> m ;
    for (i=0;i<m;i++) {
        cin >> a >> b >> c >> s;

        if (s==0) {
            adj[a].push_back(make_pair(b,c)) ;
            adj[b].push_back(make_pair(a,c)) ;
        }
        else {
            expressWay.push(make_tuple(a,b,c)) ;
        }
    }
}



void dijkstra(int start, int end) {
    //using priority queue for sort min to the top of queue
    vector<pair<int,int> > eachAdj(adj[]);

    //add 1 expressway
    tuple <int,int,int> newExpressWay = expressWay.front() ; 
    expressWay.pop() ; 
    int newA = get<0>(newExpressWay) ; 
    int newB = get<1>(newExpressWay) ; 
    int newC = get<2>(newExpressWay) ; 

    eachAdj[newA].push_back(make_pair(newB,newC));
    eachAdj[newB].push_back(make_pair(newA,newC));

    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    dist[start] = 0;
    pq.push(make_pair(0,start));
    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        
        if (visited[current]) 
            continue;
        
        visited[current] = true;
        
        if (current == end) 
            break;
        
        for (i=0 ; i < adj[current].size() ;i++) {
            int next = adj[current][i].first ;
            int weight = adj[current][i].second ;

            if (dist[current] + weight < dist[next]) {
                dist[next]  =dist[current] + weight ; 
                pq.push(make_pair(dist[next],next)) ;
            }

        }
    }
}

void eachDijkstra() {

}
int main() {
    readInput() ;
    return 0 ;
}