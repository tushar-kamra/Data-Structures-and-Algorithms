#include <bits/stdc++.h>
using namespace std ;


typedef long long ll ;

void sieveOfEratosthenes(vector<ll>& prime, ll maximum){
    bool isPrime[maximum+1]; 
    memset(isPrime, true, sizeof(isPrime)); 
 
    for (ll p=2; p*p<=maximum; p++){
        if (isPrime[p] == true){
            for (ll i=p*2; i<=maximum; i += p) 
                isPrime[i] = false; 
        } 
    } 
 
    for (ll p=2; p<=maximum; p++) 
        if (isPrime[p]) 
            prime.push_back(p); 
} 

void addFactor(unordered_map<ll,ll>& factor, ll x, vector<ll> prime){
    ll c = x ;
    for(int i=0; i<prime.size(); i++){
        while(c > 1 && c%prime[i] == 0){
            c /= prime[i] ;
            factor[prime[i]]++ ;
        }
    }
    if(c != 1){
        factor[c]++ ;
    }
} 

void addEdge(vector<ll> m[], ll u, ll v){
    m[u].push_back(v) ;
    m[v].push_back(u) ;
}

void dfs(ll u, ll v, vector<ll> m[], vector<ll>& temp, bool vis[]){
    if(u == v){
        temp.push_back(u) ;
        return ;
    }
    temp.push_back(u) ;
    ll flag = 0 ;
    vis[u] = true ;
    for(ll x : m[u]){
        if(!vis[x]){ 
            dfs(x,v,m,temp,vis) ;
            flag = 1; 
        }
    }
    if(flag == 0){
        temp.pop_back();
    }
}

int main(){
    ll t ;
    cin >> t ;
    while(t--){
        ll n ;
        cin >> n ;
        vector<ll> m[n+1] ;
        for(ll i=1; i<=n-1; i++){
            ll x, y ;
            cin >> x >> y ;
            addEdge(m,x,y) ;
        }
        ll weight[n+1] = {};
        for(ll i=1; i<=n; i++){
            cin >> weight[i] ;
        }
        ll q ;
        cin >> q ;
        while(q--){
            ll u, v ;
            cin >> u >> v ;
            vector<ll> temp ;
            bool vis[n+1] = {false} ;
            unordered_map<ll,ll> factor;
            dfs(u,v,m,temp,vis) ;
            ll maximum = weight[*max_element(temp.begin(), temp.end())] ;
            vector<ll> prime ;
            sieveOfEratosthenes(prime,maximum) ;
            for(ll i=0; i<temp.size(); i++){
                addFactor(factor,weight[temp[i]],prime) ;
            }
            ll ans = 1 ;
            for(auto it=factor.begin(); it!=factor.end(); it++){
                ans = ((ans%1000000007)*((it->second+1L)%1000000007))%1000000007 ;
            }
            cout << (ans%1000000007) << "\n" ;
        }
    }
}