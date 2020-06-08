#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std ;

typedef pair<int,pair<int,int>> ppi ;

vector<int> mergeKsorted(vector<vector<int>> v, int k){
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq ;
    vector<int> output ;

    for(int i=0; i<k; i++){
        pq.push({v[i][0], {i,0}}) ;
    }
    while(!pq.empty()){
        ppi curr = pq.top() ;
        pq.pop() ;
        int i = curr.second.first ;
        int j = curr.second.second ;
        output.push_back(curr.first) ;

        if(j+1 < v[i].size()){
            pq.push({v[i][j+1], {i,j+1}});
        }
    }
    return output ;
}

int main(){
    int k,n ;
    cin >> k ;
    vector<vector<int>> v(k);
    for(int i=0; i<k; i++){
        cin >> n ;
        v[i] = vector<int>(n) ;
        for(int j=0; j<n; j++){
            cin >> v[i][j] ;
        }
    }
    vector<int> output = mergeKsorted(v, k) ;

    for(int i=0; i<output.size(); i++){
        cout << output[i] <<" " ;
    }
}