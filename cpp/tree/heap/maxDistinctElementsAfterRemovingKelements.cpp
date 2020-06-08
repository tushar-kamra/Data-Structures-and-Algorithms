#include<iostream>
#include<unordered_map>
#include<utility>
#include<queue>

using namespace std ;

int main(){
    int n, k ;
    cin >> n >> k ;
    unordered_map<int,int> m ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    for(int i=0; i<n; i++){
         m[a[i]]++ ;
    }
    priority_queue<int> pq ;
    for(auto it=m.begin(); it!=m.end(); it++){
        pq.push(it->second);
    }

    while(k--){
        int temp = pq.top() ;
        pq.pop() ;
        temp-- ;
        if(temp!=0){
            pq.push(temp) ;
        }
    }
    int ans = 0 ;
    while(!pq.empty()){
        int x = pq.top() ;
        pq.pop() ;
        if(x == 1){
            ans++ ;
        }
    }
    cout << ans ;
}