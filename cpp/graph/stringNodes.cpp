#include<bits/stdc++.h>
using namespace std ;

class Edge {
    public: 
        string v ;
        int w ;
        Edge(string v, int w){
            this->v = v ;
            this->w = w ;
        }
};

class graph {
    private:
        int vertices ;
        unordered_map<string,vector<Edge>> GRAPH ;
        unordered_map<string,vector<Edge>>::iterator it ;
    public:
        graph(int v){
            vertices = v ;
        }
        void addEdge(string u, string v, int w){
            Edge x(v,w) ;
            GRAPH[u].push_back(x) ;
            Edge y(u,w) ;
            GRAPH[v].push_back(y) ;
        }
        void display(){
            for(it = GRAPH.begin(); it!=GRAPH.end(); it++){
                cout << it->first << " ---> " ;
                vector<Edge> e = it->second ;
                for(int i=0; i<e.size(); i++){
                    cout << e[i].v << "/" << e[i].w <<" , " ;
                }
                cout << endl ;
            }
        }

};

int main(){
    graph g(7) ;
    g.addEdge("Delhi","Mumbai",10) ;
    g.addEdge("Delhi","Bangalore",10) ;
    g.addEdge("Bangalore","Chennai",10) ;
    g.addEdge("Chennai","Mumbai",20) ;
    g.addEdge("Mumbai","Hyderabad",4) ;
    g.addEdge("Hyderabad","Pune",2) ;
    g.addEdge("Hyderabad","Goa",8) ;
    g.addEdge("Pune","Goa",3) ;
    g.display();
}