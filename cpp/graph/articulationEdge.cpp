#include<iostream>
#include<vector>
#include<queue>
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

void display(){
    for(int i = 0; i<graph.size(); i++){
        cout << i << " -> " ;
        for(int j=0; j<graph[i].size(); j++){
            cout << "( " << graph[i][j]->v <<" , " << graph[i][j]->w <<" ) " ;
        }
        cout << endl ;
    }
}

int *dis = new int[graph.size()] ;
int *low = new int[graph.size()] ;
int *par = new int[graph.size()] ;
bool *point = new bool[graph.size()] ;

int time = 0 ;
int root = 0 ;

void AP(int vtx, int parent){
    dis[vtx] = low[vtx] = time++ ;
    for(Edge* e : graph[vtx]){
        if(dis[e->v] == -1){
            par[e->v] = vtx ;
            if(parent == -1){
                root++ ;
            }
            AP(e->v,vtx) ;
            if(dis[vtx] < low[e->v]){
                point[vtx] = true ;
            }
            low[vtx] = min(low[vtx],low[e->v]) ;
        }
        else if(par[vtx] != e->v){
            low[vtx] = min(low[vtx],dis[e->v]);
        }
    }
}

int main(){
    addEdge(0,3,10) ;
    addEdge(0,1,10) ;
    addEdge(1,2,10) ;
    addEdge(2,3,40) ;
    addEdge(3,4,2) ;
    addEdge(4,5,2) ;
    addEdge(4,6,8) ;
    addEdge(5,6,3) ;
    
    cout << "Original Graph :" << endl ;
    display() ;
    for(int i=0; i<graph.size(); i++){
        dis[i] = -1 ;
        point[i] = false ;
    }
    root = 0 ;
    AP(0,-1) ;
    point[0] = root>1?true:false ;
    for(int i=0; i<graph.size(); i++){
        if(point[i]){
            cout << i << endl ;
        }
    }
}