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

class Node {
	public:
		string psf = "" ;
		int wsf = 0 ;
		int edges = 0 ;
		Node(string psf, int wsf, int edges){
			this->psf = psf ;
			this->wsf = wsf ;
			this->edges = edges ;
		}
};

bool operator<(Node n1, Node n2){
	if(n1.wsf == n2.wsf && n1.edges == n2.edges){
		return n1.psf > n2.psf ;
	}
	if(n1.wsf == n2.wsf){
		return n1.edges > n2.edges ;
	}
	return n1.wsf > n2.wsf ;
}

priority_queue<Node> pq ;

unordered_map<string,vector<Edge>> g ;
	
void addEdge(string u, string v, int w){
	Edge x(v,w) ;
	Edge y(u,w) ;
	g[u].push_back(x) ;
	g[v].push_back(y) ;
}

void allPath(string u, string v, string path, int w, int count, unordered_map<string,bool>& vis){
	if(u == v){
		string p = path+u ;
		Node n(p,w,count) ;
		pq.push(n) ;
		return;
	}
	vis[u] = true ;
	for(Edge e : g[u]){
		if(!vis[e.v]){
			allPath(e.v,v,path+u+" ",w+e.w,count+1,vis) ;
		}
	}
	vis[u] = false ;
}

int main(){
	string dcity, acity ;
	cin >> dcity >> acity ;
	vector<string> v ;
	string input ;
	cin >> ws ;
	while(getline(cin,input)){
		v.push_back(input);
	}
	vector<string> departure , arrival ;
	vector<int> cost ;
	for(int i=0; i<v.size(); i++){
		string s = v[i] ;
		stringstream obj(s) ;
		string word ;
		int c = 1 ;
		while(obj >> word){
			if(c == 1){
				departure.push_back(word) ;
			}
			else if(c == 2){
				arrival.push_back(word) ;
			}
			else {
				cost.push_back(stoi(word)) ;
			}
			c++ ;
		}
	}
	int n = departure.size();
	unordered_map<string,bool> um ;
	for(int i=0; i<n; i++){
		um[departure[i]] = false ;
		um[arrival[i]] = false ;
		addEdge(departure[i],arrival[i],cost[i]);
	}

	allPath(dcity,acity,"",0,0,um);
	
	while(!pq.empty()){
	    Node temp = pq.top();
	    cout << temp.psf << " " << temp.wsf << " " <<temp.edges << endl ;
		pq.pop();
	}
}