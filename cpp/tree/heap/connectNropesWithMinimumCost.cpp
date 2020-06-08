#include<iostream>
#include<queue>

using namespace std ;

int main(){
    int n, sum=0 ;
    cin >> n ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    int i = 0 ;
    cout << "i = "<<i++<<endl ;
    priority_queue<int, vector<int>, greater<int>> pq(a,a+n) ;
    while (!pq.empty()){
        int a = pq.top();
        pq.pop() ;
        if(pq.empty()) break ;
        int b = pq.top() ;
        pq.pop() ;
        sum += a+b ;
        pq.push(a+b) ;
    }
    cout << sum ;
}