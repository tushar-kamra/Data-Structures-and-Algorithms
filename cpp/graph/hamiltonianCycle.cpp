#include<iostream>
#include<vector>
using namespace std ;

class Edge {
    public :
        int v = 0 ;
        int w = 0 ;

        Edge(int v, int w){
            this->v = v ;
            this->w = w ;
        }
};

vector<vector<Edge*>> graph(7, vector<Edge*>()) ;

void addEdge(int u, int v, int w){
    if(u<0 || v<0 || u>=graph.size() || v>=graph.size()){
        return ;
    }
    graph[u].push_back(new Edge(v,w)) ;
    graph[v].push_back(new Edge(u,w)) ;
}

void hamiltonianCycle(int src, int osrc, int count, int dest, string ans, bool visited[]){
    if(count == graph.size()-1){
        cout << ans + to_string(src) ;
        for(Edge* e : graph[src]){
            if(e->v == osrc){
                cout << " -> Cycle" ;
            }
        }
        cout << endl ;
        return ;
    }
    visited[src] = true ;
    for(Edge* e : graph[src]){
        int v = e->v ;
        if(!visited[v]){
            hamiltonianCycle(v,osrc,count+1,dest,ans+to_string(src)+" ",visited) ;
        }
    }
    visited[src] = false ;
}

void display(){
    for(int i = 0; i<graph.size(); i++){
        cout << i << " -> " ;
        for(int j=0; j<graph[i].size(); j++){
            cout << "( " << graph[i][j]->v <<" , " << graph[i][j]->w <<" ) " ;
        }
        cout << endl ;
    }
}

int main(){
    addEdge(0,3,10) ;
    addEdge(0,1,10) ;

    // addEdge(1,0,10) ;
    addEdge(1,2,10) ;

    // addEdge(2,1,10) ;
    addEdge(2,3,40) ;
    addEdge(2,5,13) ;

    // addEdge(3,0,10) ;
    addEdge(3,4,2) ;
    // addEdge(3,2,40) ;

    // addEdge(4,3,2) ;
    addEdge(4,5,2) ;
    addEdge(4,6,8) ;

    // addEdge(5,4,2) ;
    addEdge(5,6,3) ;

    // addEdge(6,5,3) ;
    // addEdge(6,4,8) ;

    display() ;
    bool visited[7] = {false} ;
    hamiltonianCycle(2,2,0,6,"",visited) ;
}