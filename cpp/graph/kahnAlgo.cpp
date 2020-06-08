#include<iostream>
#include<vector>
#include<queue>

using namespace std ;

class Edge {
    public:
        int v ;
        Edge(int v){
            this->v = v ;
        }
};

vector<vector<Edge*>> graph(7,vector<Edge*>()) ;

void insert(int u, int v){
    if(u<0 || v<0 || u>=graph.size() || v>=graph.size()) return ;
    graph[u].push_back(new Edge(v)) ;
}

void kahnsAlgo(){
    int indegree[6] = {} ;
    for(int i=0; i<graph.size(); i++){
        for(int j=0; j<graph[i].size(); j++){
            indegree[graph[i][j]->v]++ ;
        }
    }
    queue<int> q ;
    for(int i=0; i<6; i++){
        if(indegree[i]==0) q.push(i) ;
    }
    while(!q.empty()){
        int curr = q.front() ;
        q.pop() ;
        cout << curr << " " ;
        for(int i=0; i<graph[curr].size(); i++){
            indegree[graph[curr][i]->v]-- ;
            if(indegree[graph[curr][i]->v] == 0){
                q.push(graph[curr][i]->v) ;
            }
        }
    }
}

int main(){
    insert(0,1) ;
    insert(1,2) ;
    insert(2,3) ;
    insert(0,5) ;
    insert(4,5) ;
    insert(5,3) ;
    kahnsAlgo() ;
}