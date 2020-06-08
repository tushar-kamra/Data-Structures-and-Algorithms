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

int height(Node* root){
    if(root == NULL){
        return 0 ;
    }
    int lheight = height(root->left) ;
    int rheight = height(root->right) ;
    return (max(lheight,rheight)+1) ;
}

void print(Node* root, int k){
    if(root == NULL) return ;
    if(k == 0){
        cout << root->data << " " ;
        return ;
    }
    print(root->left, k-1) ;
    print(root->right, k-1) ;
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

    int k ;
    cin >> k ;
    print(root,k) ;
    
}