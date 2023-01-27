#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//define Variable
int n, m, i, u, v, w ;
const int INF = 0xfffffff ; 
vector<pair<int, int> > adj[100001];
int dist[100001] ;
bool visited[100001] ;

//input

void init() {
    for (i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false ;
    }
}
void readInput() {

    cin >> n >> m;
    for (i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    return;
}

void dijkstra(int start, int end) {
    //using priority queue for sort min to the top of queue
    priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
    
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

int main() {
    readInput();
    init();
    dijkstra(1, n);
    cout << dist[n];
}