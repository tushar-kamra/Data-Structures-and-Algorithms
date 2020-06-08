#include<iostream>
#include<vector>
#include<utility>
using namespace std ;

typedef long long ll ;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    ll n,q ;
    cin >> n >> q ;
    ll a[n+1] = {} ;
    for(int i=1; i<=n; i++){
        cin >> a[i] ;
    }
    vector< pair<ll,ll> > v ;
    v.push_back(make_pair(0,0)) ;
    int flag = 0 ;
    ll countMax = 0, countMin = 0 ;
    for(ll i=1; i<n; i++){
        if(a[i] < a[i+1]){
            if(!flag){
                countMax++ ;
                flag = 1 ;
            }
        }
        else {
            if(flag){
                countMin++ ;
                flag = 0 ;
            }
            else if(i == 1){
                flag = 1 ;
                i-- ;
            }
        }
        v.push_back({countMax,countMin}) ;
    }
    for(int i=0; i<v.size(); i++){
        cout <<"( " << v[i].first <<" , "<<v[i].second << " )\n" ;
    }
    while(q--){
        ll l,r ;
        cin >> l >> r ;
        if(v[r-1].first - v[l-1].first == v[r-1].second - v[l-1].second){
            cout << "YES" << endl ;
        }
        else {
            cout << "NO" << endl ;
        }
    }
}


// #include<iostream>
// using namespace std ;

// typedef long long ll ;

// int main(){
//     ios_base::sync_with_stdio(false) ;
//     cin.tie(0) ;
//     cout.tie(0) ;
//     ll n,q ;
//     cin >> n >> q ;
//     ll a[n+1] = {} ;
//     for(int i=1; i<=n; i++){
//         cin >> a[i] ;
//     }
//     while(q--){
//         ll l,r ;
//         cin >> l >> r ;
//         ll countMax = 0, countMin = 0, flag = 0;
//         for(ll i=l; i<r; i++){
//             if(a[i] < a[i+1]){
//                 if(flag){
//                     continue ;
//                 }
//                 else {
//                     countMax++ ;
//                     flag = 1 ;
//                 }
//             }
//             else {
//                 if(flag){
//                     countMin++ ;
//                     flag = 0 ;
//                 }
//                 else if(i == l){
//                     flag = 1 ;
//                     i-- ;
//                 }
//                 else {
//                     continue ;
//                 }
//             }
//         }
//         if(countMin == countMax){
//             cout << "YES" << endl ;
//         }
//         else {
//             cout << "NO" << endl ;
//         }
//     }
// }