// Program to find shortest path, cycle and length of the shortest path

#include<iostream>
#include<list>
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

class Node {
    public:
        int v = 0;
        int wsf = 0 ;
        string psf = "" ;

        Node(int v, int wsf, string psf){
            this->v = v ;
            this->wsf = wsf ;
            this->psf = psf ;
        }
        
        Node(){
        }
} ;

vector<vector<Edge*>> graph(7, vector<Edge*>()) ;

void addEdge(int u, int v, int w){
    if(u<0 || v<0 || u>=graph.size() || v>=graph.size()){
        return ;
    }
    graph[u].push_back(new Edge(v,w)) ;
    graph[v].push_back(new Edge(u,w)) ;
}

int cycle(Node* source, int d, bool visited[]){
    bool isPath = false ;
    int level = 0 ;
    int cycleCount = 0 ;
    list<Node*> l ;
    int n = graph.size() ;
    l.push_back(source) ;
    l.push_back(NULL) ;
    while(l.size()!=1){
        Node* curr = l.front() ;
        l.pop_front() ;
        if(visited[curr->v] == 1){
            cycleCount++ ;
            cout << cycleCount <<" Cycle @ " << curr->psf << endl ;
        }
        if(curr->v == d && !isPath){
            cout << curr->psf << " Length = " << level << endl ;
            isPath = true ;
        }
        visited[curr->v] = 1 ;
        for(Edge* e : graph[curr->v]){
            if(!visited[e->v]){
                int weight_so_far = curr->wsf + e->w ;
                string path_so_far = curr->psf + char('0'+e->v) + " " ;
                Node* temp = new Node(e->v, weight_so_far, path_so_far ) ;
                l.push_back(temp) ;
            }
        }
        if(l.front() == NULL){
            level++ ;
            l.pop_front() ;
            l.push_back(NULL) ;
        }
    }
    return cycleCount ;
}

int main(){
    addEdge(0,1,10) ;
    addEdge(0,3,10) ;

    addEdge(1,2,10) ;

    addEdge(2,3,40) ;
    //addEdge(2,5,13) ;

    //addEdge(3,4,2) ;

    addEdge(4,5,2) ;
    addEdge(4,6,8) ;

    //addEdge(5,6,3) ;

    
    bool visited[graph.size()] = {} ;
    int c = 1 ;
    for(int i=0; i<graph.size(); i++){
        if(!visited[i]){
            Node* source = new Node(i,0,to_string(i)) ;
            int cyc = cycle(source,6,visited) ;
            c++ ;
        }
    }
    cout << "Disconnected component = " << c << endl ;
}

