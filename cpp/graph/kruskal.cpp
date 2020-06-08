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

class kpair {
    public :
        int u = 0 ;
        int v = 0 ;
        int w = 0 ;
        kpair(int u, int v, int w){
            this->u = u ;
            this->v = v ;
            this->w = w ;
        }
};

bool operator<(const kpair& p1, const kpair& p2){
    return p1.w > p2.w ;
}

vector<vector<Edge*>> graph(9, vector<Edge*>()) ;
vector<vector<Edge*>> mst(9, vector<Edge*>()) ;
priority_queue<kpair> pq ;
int parent[9] ;
int total[9] ;

void addEdge(int u, int v, int w){
    if(u<0 || v<0 || u>=graph.size() || v>=graph.size()){
        return ;
    }
    pq.push(kpair(u,v,w)) ;
    graph[u].push_back(new Edge(v,w)) ;
    graph[v].push_back(new Edge(u,w)) ;
}

void addEdge2(int u, int v, int w){
    if(u<0 || v<0 || u>=mst.size() || v>=mst.size()){
        return ;
    }
    mst[u].push_back(new Edge(v,w)) ;
    mst[v].push_back(new Edge(u,w)) ;
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
    for(int i = 0; i<mst.size(); i++){
        cout << i << " -> " ;
        for(int j=0; j<mst[i].size(); j++){
            cout << "( " << mst[i][j]->v <<" , " << mst[i][j]->w <<" ) " ;
        }
        cout << endl ;
    }
}

int find(int vtx){
    if(parent[vtx] != vtx){
        parent[vtx] = find(parent[vtx]) ;
    }
    return parent[vtx] ;
}

void Union(int pt1, int pt2){
    if(total[pt1] <= total[pt2]){
        parent[pt1] = pt2 ;
        total[pt2] += total[pt1] ;
    }
    else {
        parent[pt2] = pt1 ;
        total[pt1] += total[pt2] ;
    }
}

void kruskal(){
    for(int i=0; i<graph.size(); i++){
        parent[i] = i ;
        total[i] = 1 ;
    }
    while(!pq.empty()){
        kpair rpair = pq.top() ;
        pq.pop() ;
        int pt1 = find(rpair.u) ;
        int pt2 = find(rpair.v) ;
        if(pt1 != pt2){
            addEdge2(rpair.u, rpair.v, rpair.w) ;
            Union(pt1, pt2) ;
        }
    }
    cout << " MST : \n" ;
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

    kruskal() ;
}