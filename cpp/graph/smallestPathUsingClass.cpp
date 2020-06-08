#include<iostream>
#include<vector>
#include<climits>
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

class pair_path {
    public :
        int wt = INT_MAX ;
        string s = "" ;
        pair_path(int wt, string s){
            this->wt = wt ;
            this->s = s ;
        }
        pair_path(){
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

pair_path* smallestPath(int u, int d, bool visited[7]){
    if(u == d){
        pair_path* obj = new pair_path(0,to_string(u)+" ");
        return obj ;
    }
    visited[u] = true ;
    pair_path* myAns = new pair_path() ;
    for(Edge* e : graph[u]){
        int v = e->v ;
        int w = e->w ;
        if(!visited[v]){
            pair_path* recAns = smallestPath(v,d,visited);
            if(recAns->wt + w < myAns->wt){
                myAns->wt = recAns->wt + w ;
                myAns->s = to_string(u) + recAns->s ;
            }
        }
    }
    visited[u] = false ;
    return myAns ;
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

    cout << "Enter destination : " ;
    int d ;
    cin >> d ;
    string ans = "" ;
    bool visited[7] = {false} ;
    pair_path* temp = smallestPath(0,d,visited) ;
    cout << endl;
    cout << " Answer : " << temp->s << endl ;
    cout << "Weight : " << temp->wt ;
}