#include<iostream>
#include<queue>
#include<map>
using namespace std ;

struct Node {
    int data ;
    Node* left ;
    Node* right ;
    Node* parent ;
};

Node* createNode(int x){
    Node* temp = new Node() ;
    temp->data = x ;
    temp->left = NULL ;
    temp->right = NULL ;
    temp->parent = NULL ;
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
            temp->left->parent = temp ;
            break ;
        }
        else {
            q.push(temp->left) ;
        }
        if(!temp->right){
            temp->right = createNode(x) ;
            temp->right->parent = temp ;
            break ;
        }
        else {
            q.push(temp->right) ;
        }
    }
    return root ;
}

int depth(Node* n){
    int d = -1 ;
    while(n){
        d++ ;
        n = n->parent ;
    }
    return d ;
}

Node* lca(Node* root, Node* n1, Node* n2){
    int d1 = depth(n1), d2 = depth(n2) ;
    int diff = d1-d2 ;
    if(diff < 0){
        swap(n1,n2) ;
    }
    while(diff--){
        n1 = n1->parent ;
    }
    while(n1 && n2){
        if(n1 == n2) return n1 ;
        n1 = n1->parent ;
        n2 = n2->parent ;
    }
    return NULL ;
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
    
    Node* n1 = root1->left->left->right ;
    Node* n2 = root1->left->right->right ;
    cout << lca(root1,n1,n2)->data ;
}