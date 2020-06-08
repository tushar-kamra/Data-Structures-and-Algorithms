#include<iostream>
#include<queue>
using namespace std ;

struct Node {
    string s ;
    Node* left ;
    Node* right ;
};

Node* createNode(string x){
    Node* temp = new Node() ;
    temp->s = x ;
    return temp ;
}

void binaries(int n){
    Node* root = createNode("1") ;
    int i = 1 ;
    queue<Node*> q ;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->s << endl ;
        q.push(createNode(temp->s + "0"));
        q.push(createNode(temp->s + "1"));
        if(i == n){
            break ;
        }
        i++ ;
    }
}

int main(){
    int n ;
    cin >> n ;
    binaries(n) ;
}