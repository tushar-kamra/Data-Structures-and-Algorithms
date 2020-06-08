#include <bits/stdc++.h>
using namespace std ;

#define SIEVE_SIZE 1000001
typedef long ll ;

ll spf[SIEVE_SIZE];

class Edge {
    public:
        ll v ;
        Edge(ll v){
            this->v = v ;
        }
};

class Node {
    public:
        ll nodeNumber ;
        ll weight ;
        ll parent ;
        unordered_map<ll,ll> factors ;
        Node(ll nodeNumber, ll weight, ll parent){
            this->nodeNumber = nodeNumber ;
            this->weight = weight ;
            this->parent = parent ;
        }
};

void sieve() {
    spf[1] = 1; 
    for (ll i=2; i<SIEVE_SIZE; i++) 
        spf[i] = i; 
  
    for (ll i=4; i<SIEVE_SIZE; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<SIEVE_SIZE; i++) {
        if (spf[i] == i) {
            for (ll j=i*i; j<SIEVE_SIZE; j+=i) {
                if (spf[j]==j) 
                    spf[j] = i; 
            }
        } 
    } 
} 

void addFactor(unordered_map<ll,ll>& factor, ll x) 
{ 
    while (x != 1) 
    { 
        factor[spf[x]]++ ;
        x = x / spf[x]; 
    } 
} 

void addEdge(ll u, ll v, unordered_map<ll,vector<ll>>& tree){
    tree[u].push_back(v) ;
    tree[v].push_back(u) ;
}

void printMap(unordered_map<ll,ll> factors){
    for(auto it = factors.begin(); it!=factors.end(); it++){
        cout << it->first <<" " << it->second << endl ;
    }
}

unordered_map<ll,Node*> mp ;

void bfs(int n, unordered_map<ll, vector<ll>>& tree, ll weight[]){
    Node* src = new Node(1,weight[1],-1);
    addFactor(src->factors,weight[1]);
    queue<Node*> q ;
    q.push(src) ;
    bool vis[n+1] = {false} ;
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        mp[curr->nodeNumber] = curr ;
        // cout << "Node number = " << curr->nodeNumber << " Weight = " << curr->weight << endl ;
        // cout << "Prime factorization till " << curr->nodeNumber << endl ;
        // printMap(curr->factors) ;
        vis[curr->nodeNumber] = true ;
        for(ll e : tree[curr->nodeNumber]){
            if(!vis[e]){
                Node* temp = new Node(e,weight[e],curr->nodeNumber);
                temp->factors = curr->factors ;
                addFactor(temp->factors,weight[e]);
                q.push(temp);
            }
        }
    }
}

ll lca(ll u, ll v){
    ll p1 = u ;
    ll p2 = v ;
    while(p1 && p2){
        if(p1 == p2){
            return p1 ;
        }
        if(p1 == 1 || p2 == 1){
            return 1 ;
        }
        p1 = mp[p1]->parent ;
        p2 = mp[p2]->parent ;
    }
    return -1 ;
}

int main(){
    int t ;
    cin >> t ;
    sieve();
    while(t--){
        ll n ;
        cin >> n ;
        ll weight[n+1] ;
        unordered_map<ll,vector<ll>> tree ;
        for(ll i=1; i<=n-1; i++){
            ll x, y ;
            cin >> x >> y ;
            addEdge(x,y,tree) ;
        }
        for(ll i=1; i<=n; i++){
            cin >> weight[i] ;
        }
        bfs(n,tree,weight);
        ll q ;
        cin >> q ;
        while(q--){
            ll ans = 1 ;
            ll u, v ;
            cin >> u >> v ;
            if(u == 1){
                unordered_map<ll,ll> temp =  mp[v]->factors ;
                for(auto it=temp.begin(); it!=temp.end(); it++){
                    ans = ans*(it->second+1) ;
                }
            }
            else if(v == 1){
                unordered_map<ll,ll> temp =  mp[u]->factors ;
                for(auto it=temp.begin(); it!=temp.end(); it++){
                    ans = ans*(it->second+1) ;
                }
            }
            // else if(u == v){
            //     unordered_map<ll,ll> temp =  mp[u]->factors ;
            //     for(auto it=temp.begin(); it!=temp.end(); it++){
            //         ans = ans*(it->second+1) ;
            //     }
            // }
            else {
                ll x = lca(u,v) ;
                unordered_map<ll,ll> map1 = mp[u]->factors ;
                unordered_map<ll,ll> map2 = mp[v]->factors ;
                unordered_map<ll,ll> map3 = mp[x]->factors ;
                
                unordered_map<ll,ll> sumMap1 ;
                for(auto it = map1.begin(); it!=map1.end(); it++){
                    sumMap1[it->first] += map1[it->first] ;
                }
                for(auto it = map2.begin(); it!=map2.end(); it++){
                    sumMap1[it->first] += map2[it->first] ;
                }
                for(auto it = map3.begin(); it!=map3.end(); it++){
                    sumMap1[it->first] = abs(sumMap1[it->first] - map3[it->first]) ;
                }
                if(x!=1){
                    unordered_map<ll,ll> map4 = mp[mp[x]->parent]->factors ;
                    for(auto it = map4.begin(); it!=map4.end(); it++){
                        sumMap1[it->first] = abs(sumMap1[it->first] - map4[it->first]) ;
                    }
                }
                for(auto it=sumMap1.begin(); it!=sumMap1.end(); it++){
                    ans = (ans*(it->second+1))%1000000007 ;
                }
            }
            cout << ans%1000000007 << endl ;
        }
    }
}