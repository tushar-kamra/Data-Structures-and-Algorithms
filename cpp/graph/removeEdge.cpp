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

bool removeEdge(int u, int v){
    if(u < 0 || v < 0 || u >= graph.size() || v >= graph.size()){
        return false ;
    }
    int idx,i ;
    for(i=0; i<graph[u].size(); i++){
        if(graph[u][i]->v == v){
            idx = i ;
            break ;
        }
    }
    if(i != graph[u].size()){
        graph[u].erase(graph[u].begin()+i) ;
        return true ;
    }
    return false ;
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

    if(removeEdge(5,6)){
        cout << "Edge removed \n" ;
    }
    else {
        cout << "No edge found \n" ;
    }

    display() ;
}