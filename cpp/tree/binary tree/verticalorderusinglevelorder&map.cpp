#include<iostream>
#include<queue>
#include<map>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    return temp ;
}

Node* insertNode(Node* root, int x){
    if(root == NULL){
        root = createNode(x) ;
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(!temp->left){
            temp->left = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->left) ;
        }
        if(!temp->right){
            temp->right = createNode(x) ;
            break ;
        }
        else {
            q.push(temp->right) ;
        }
    }
    return root ;
}


void verticalorder(Node* root){
    int hd = 0 ;
    map<int,vector<int>> m ;
    queue<pair<int,Node*>> q ;
    q.push(make_pair(hd,root)) ;
    Node* temp ;
    while(!q.empty()){
        pair<int, Node*> p = q.front() ;
        q.pop() ;
        hd = p.first ;
        temp = p.second ;
        m[hd].push_back(temp->data) ;
        if(temp->left){
            q.push(make_pair(hd-1,temp->left)) ;
        }
        if(temp->right){
            q.push(make_pair(hd+1,temp->right)) ;
        }
    }

    for(auto it = m.begin(); it!=m.end(); it++){
        for(int i=0; i<it->second.size(); i++){
            cout << it->second[i] <<" " ;
        }
        cout << endl ;
    }
}

int main(){
    Node* root = NULL ;
    root = insertNode(root,2);
    root = insertNode(root,4);
    root = insertNode(root,1);
    root = insertNode(root,8);
    root = insertNode(root,6);
    root = insertNode(root,5);
    root = insertNode(root,7);
    root = insertNode(root,9);
    root = insertNode(root,11);
    root = insertNode(root,16);
    root = insertNode(root,25);
    root = insertNode(root,27);
    root = insertNode(root,3);
    root = insertNode(root,17);

    verticalorder(root) ;
}