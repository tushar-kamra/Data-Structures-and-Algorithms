#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

class Edge {
    public :
        int v ;
        Edge(){

        }
        Edge(int v){
            this->v = v ;
        }
};

vector< vector<Edge*> > graph(6,vector<Edge*>()) ;

void addEdge(int u, int v){
    if(u < 0 || v < 0 || u >= graph.size() || v >= graph.size()) {
        return ;
    }
    graph[u].push_back(new Edge(v)) ;
    graph[v].push_back(new Edge(u)) ;
}

bool isBipartite(int src){
    /*
        -1 => No color
        0 => first color
        1 => second color
    */
    int color[6] ;
    for(int i=0; i<6; i++){
        color[i] = -1 ;
    }
    queue<int> q ;
    q.push(src) ;
    color[src] = 0 ;
    while(!q.empty()){
        int u = q.front() ;
        q.pop() ;
        for(Edge* e : graph[u]){
            int v = e->v ;
            if(color[v] == color[u]){
                return false ;
            }
            else if(color[v] == -1){
                color[v] = 1-color[u] ;
                q.push(v) ;
            }
        }
    }
    return true ;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout << i << " => " ;
        for(int j=0; j<graph[i].size(); j++){
            cout << graph[i][j]->v << " " ;
        }
        cout << endl ;
    }
}

int main(){
    addEdge(0,1) ;
    addEdge(1,2) ;
    addEdge(2,3) ;
    addEdge(3,0) ;
    addEdge(4,5) ;
    display() ;
    if(isBipartite(0)){
        cout << "Bipartite graph" ;
    }
    else {
        cout << "Not a bipartite graph" ;
    }
}