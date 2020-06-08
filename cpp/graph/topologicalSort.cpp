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

// return true if cycle is present
bool topologicalSort_(int src, vector<int>& st, vector<bool>& vis, vector<bool>& cycle){
    vis[src] = true ;
    cycle[src] = true ;
    bool res = false ;

    for(Edge* e : graph[src]){
        if(!vis[e->v]){
            res = res || topologicalSort_(e->v,st,vis,cycle) ;
        }
        else if(cycle[e->v]){
            return true ;
        }
    }

    st.push_back(src) ;
    cycle[src] = false ;
    return res ;
}

void topologicalSort(){
    vector<int> st ;
    vector<bool> vis(graph.size(),false) ;
    vector<bool> cycle(graph.size(),false) ;
    bool res = false ;

    for(int i=0; i<graph.size(); i++){
        if(!vis[i]){
            if(topologicalSort_(i,st,vis,cycle)){
                res = true ;
            }
        }
    }

    for(int i=st.size()-1; i>=0 && !res ; i--){
        cout <<  st[i] << " " ;
    }
}

int main(){
    addEdge(0,1,10) ;
    addEdge(0,5,10) ;
    addEdge(1,2,10) ;
    addEdge(2,3,40) ;
    addEdge(4,5,2) ;
    addEdge(4,6,3) ;
    addEdge(6,3,1) ;

    topologicalSort() ;
}