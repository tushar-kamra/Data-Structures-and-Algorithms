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

void verticalorder(Node* root, int hd, map<int,vector<int>> &m){
    if(root == NULL){
        return ;
    }
    m[hd].push_back(root->data) ;
    verticalorder(root->left, hd-1, m) ;
    verticalorder(root->right, hd+1, m) ;
}

void print(map<int,vector<int>> m){
    map<int,vector<int>>::iterator it ;
    for(it = m.begin(); it!=m.end(); it++){
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

    map<int,vector<int>> m ;
    verticalorder(root,0,m) ;
    print(m) ;
}