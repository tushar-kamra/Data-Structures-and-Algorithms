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

bool ancestors(Node* root, int x){
    if(root == NULL){
        return false ;
    }
    if(root->data == x){
        return true ;
    }
    if(ancestors(root->left,x) || ancestors(root->right,x)){
        cout << root->data <<" " ;
        return true ;
    }
    return false ;
}

int main(){
    Node* root1 = NULL ;
    
    root1 = insertNode(root1,2);
    root1 = insertNode(root1,4);
    root1 = insertNode(root1,1);
    root1 = insertNode(root1,8);
    root1 = insertNode(root1,6);
    root1 = insertNode(root1,5);
    root1 = insertNode(root1,7);
    root1 = insertNode(root1,9);
    root1 = insertNode(root1,11);
    root1 = insertNode(root1,16);
    root1 = insertNode(root1,25);
    root1 = insertNode(root1,27);
    root1 = insertNode(root1,3);
    root1 = insertNode(root1,17);
    
    int n ;
    cin >> n ;
    ancestors(root1,n) ;
}