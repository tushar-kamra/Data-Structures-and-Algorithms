#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<utility>
#include<vector>

using namespace std ;

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.second == p2.second){
        return p1.first > p2.first ;
    }
    return p1.second > p2.second ;
}

int main(){
    int n,k ;
    cin >> n >> k ;
    int a[n] ;
    for(int i=0; i<n; i++){
        cin >> a[i] ;
    }
    unordered_map<int,int> m ;
    for(int i=0; i<n; i++){
        m[a[i]]++ ;
    }
    vector< pair<int,int> > v(m.begin(),m.end()) ;

    cout <<"Before sorting : \n" ;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" " <<v[i].second << endl ;
    }

    sort(v.begin(), v.end(), compare) ;

    cout<<"After sorting : \n" ;
    for(int i=0; i<v.size(); i++){
        cout << v[i].first <<" " <<v[i].second << endl ;
    }
}