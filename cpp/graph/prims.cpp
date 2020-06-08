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

class dpair {
    public :
        int vtx = 0 ;
        int pvtx = 0 ;
        int w = 0 ;
        string psf = "" ;
        dpair(int vtx, int pvtx, int w, string psf){
            this->vtx = vtx ;
            this->pvtx = pvtx ;
            this->w = w ;
            this->psf = psf ;
        }
};

bool operator<(const dpair& p1, const dpair& p2){
    return p1.w > p2.w ;
}

vector<vector<Edge*>> graph(7, vector<Edge*>()) ;
vector<vector<Edge*>> pgraph(7, vector<Edge*>()) ;

void addEdge(int u, int v, int w){
    if(u<0 || v<0 || u>=graph.size() || v>=graph.size()){
        return ;
    }
    graph[u].push_back(new Edge(v,w)) ;
    graph[v].push_back(new Edge(u,w)) ;
}

void addEdge2(int u, int v, int w){
    if(u<0 || v<0 || u>=pgraph.size() || v>=pgraph.size()){
        return ;
    }
    pgraph[u].push_back(new Edge(v,w)) ;
    pgraph[v].push_back(new Edge(u,w)) ;
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

void display2(){
    for(int i = 0; i<pgraph.size(); i++){
        cout << i << " -> " ;
        for(int j=0; j<pgraph[i].size(); j++){
            cout << "( " << pgraph[i][j]->v <<" , " << pgraph[i][j]->w <<" ) " ;
        }
        cout << endl ;
    }
}

void prims(int src){
    dpair root(src,-1,0,to_string(src)+ " ") ;
    priority_queue <dpair> pq ;
    pq.push(root) ;
    vector<bool> vis(graph.size(), false) ;
    while(!pq.empty()){
        dpair rpair = pq.top() ;
        pq.pop() ;
        if(vis[rpair.vtx]){
            continue ;
        }
        if(rpair.pvtx != -1){
            addEdge2(rpair.vtx, rpair.pvtx, rpair.w) ;
        }
        vis[rpair.vtx] = true ;
        for(Edge* e : graph[rpair.vtx]){
            if(!vis[e->v]){
                dpair npair(e->v, rpair.vtx, e->w, rpair.psf + " " + to_string(e->v) ) ;
                pq.push(npair) ;
            }
        }
    } 
    display2() ;
}

int main(){
    addEdge(0,1,4) ;
    addEdge(0,7,8) ;
    addEdge(1,7,11) ;
    addEdge(1,2,8) ;
    addEdge(2,3,7) ;
    addEdge(2,5,4) ;
    addEdge(2,8,2) ;
    addEdge(3,4,9) ;
    addEdge(3,5,14) ;
    addEdge(4,5,10) ;
    addEdge(4,6,8) ;
    addEdge(5,6,2) ;
    addEdge(6,8,6) ;
    addEdge(7,8,7) ;
    
    cout << "Original Graph :" << endl ;
    display() ;

    prims(0) ;
}