#include<iostream>
#include<queue>
#include<vector>

using namespace std ;

class Edge {
    public:
        int v = 0 ;
        int w = 0 ;
        Edge(int v, int w){
            this->v = v ;
            this->w = w ;
        }
};

class Node {
    public :
        int v = 0 ;
        string psf = "" ;
        Node(int v, string psf){
            this->v = v ;
            this->psf = psf ;
        }
};

vector< vector<Edge*> > graph(7,vector<Edge*>()) ;

void addEdge(int u, int v, int w){
    if(u<0 || v<0 || u>= graph.size() || v >= graph.size()){
        return ;
    }
    graph[u].push_back(new Edge(v,w)) ;
    graph[v].push_back(new Edge(u,w)) ;
}

void display(){
    for(int i=0; i<graph.size(); i++){
        cout << i <<" -> " ;
        for(int j=0; j<graph[i].size(); j++){
            cout << "(" << graph[i][j]->v <<","<<graph[i][j]->w << ") " ;
        }
        cout << endl ;
    }
}

void pathUsingBFS(Node* src, int d){
    int n = graph.size() ;
    int level = 0 ;
    bool visited[n] = {} ;
    queue<Node*> q ;
    q.push(src) ;
    q.push(NULL) ;
    while(q.size()!=1){
        Node* curr = q.front() ;
        q.pop() ;
        if(curr->v == d){
            cout << "Path = " << curr->psf << endl ;
            cout << "Level = " << level << endl ;
        }
        visited[curr->v] = 1 ;
        for(Edge* e : graph[curr->v]){
            if(!visited[e->v]){
                Node* temp = new Node(e->v,curr->psf + char('0'+e->v) + " ") ;
                q.push(temp) ;
            }
        }
        if(q.front() == NULL){
            level++ ;
            q.pop() ;
            q.push(NULL) ;
        }
    }

}

int main(){
    addEdge(0,1,10) ;
    addEdge(0,3,10) ;
    addEdge(1,2,10) ;
    addEdge(2,3,40) ;
    addEdge(2,5,13) ;
    addEdge(3,4,2) ;
    addEdge(4,5,2) ;
    addEdge(4,6,8) ;
    addEdge(5,6,3) ;
    display() ;
    Node* src = new Node(0,"0 ") ;
    pathUsingBFS(src,6) ;
}