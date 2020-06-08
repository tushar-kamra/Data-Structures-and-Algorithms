#include<iostream>
#include<queue>
#include<stack>
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

void preorder(Node* root){
    if(root == NULL){
        return ;
    }
    cout << root->data <<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}

void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left) ;
    cout << root->data <<" " ;
    inorder(root->right) ;
}

void iterinorder(Node* root){
    stack<Node*> s ;
    while(true){
        while(root){
            s.push(root) ;
            root = root->left ;
        }
        if(s.empty()){
            break ;
        }
        root = s.top();
        cout << root->data <<" " ;
        s.pop();
        root = root->right ;
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
    cout << "Inorder recursive : " ;
    inorder(root) ;
    cout << endl ;
    cout << "Inorder iterative : " ;
    iterinorder(root) ;
    cout << endl ;
    
}