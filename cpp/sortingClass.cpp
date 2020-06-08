#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std ;

class Edge {
    public :
        int u ;
        int v ;
        int w ;
        Edge(int u, int v, int w){
            this->u = u ;
            this->v = v ;
            this->w = w ;
        }
};

bool operator<(const Edge& e1, const Edge& e2){
    return e1.w > e2.w ;
}

int main(){
    vector<Edge> v { {0,3,10} , {0,1,10} , {1,2,10} , {2,3,40} , {3,4,2} , {4,5,2} , {4,6,8} , {5,6,3} } ;
    int k = 8 ;
    Edge a[8] = { {0,3,10} , {0,1,10} , {1,2,10} , {2,3,40} , {3,4,2} , {4,5,2} , {4,6,8} , {5,6,3} } ;
    priority_queue<Edge,vector<Edge>> pq(a,a+8) ;
    cout << "Before sorting : " << endl ;
    for(int i=0; i<v.size(); i++){
        cout << v[i].u << " " << v[i].v << " " << v[i].w << endl ;
    }
    sort(v.begin(), v.end()) ;
    cout << "After sorting : \n" ;
    for(int i=0; i<v.size(); i++){
        cout << v[i].u << " " << v[i].v << " " << v[i].w << endl ;
    }
    cout << "PQ :\n" ;
    while(!pq.empty()){
        cout << pq.top().u <<" " << pq.top().v << " " << pq.top().w << endl ;
        pq.pop() ;
    }
}