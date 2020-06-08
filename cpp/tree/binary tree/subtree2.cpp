#include<iostream>
#include<queue>
#include<map>
#include<cstring>
#include<string>
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

void inorder(Node* root, string &s){
    if(root == NULL){
        s += "$" ;
        return ;
    }
    inorder(root->left,s) ;
    s += to_string(root->data);
    inorder(root->right,s) ;
}

void preorder(Node* root, string &s){
    if(root == NULL){
        s += "$" ;
        return ;
    }
    s += to_string(root->data);
    preorder(root->left,s) ;
    preorder(root->right,s) ;
}

bool isSubtree(Node* parent, Node* child){
    string inChild, inParent, preChild, preParent ;
    inorder(parent,inParent) ;
    inorder(child,inChild) ;
    if(inParent.find(inChild) == string::npos){
        return false ;
    }
    preorder(child,preChild) ;
    preorder(parent, preParent) ;
    return (preParent.find(preChild) != string::npos) ;
}

int main(){
    Node* root1 = NULL ;
    Node* root2 = NULL ;
    
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
    
    // root2 = insertNode(root2,2);
    // root2 = insertNode(root2,4);
    root2 = insertNode(root2,1);
    root2 = insertNode(root2,5);
    root2 = insertNode(root2,7);
    root2 = insertNode(root2,27);
    root2 = insertNode(root2,3);
    root2 = insertNode(root2,17);
    
    // root2 = insertNode(root2,11);
    // root2 = insertNode(root2,16);
    // root2 = insertNode(root2,25);
    // root2 = insertNode(root2,27);
    // root2 = insertNode(root2,3);
    // root2 = insertNode(root2,17);

    (isSubtree(root1,root2))?cout << "True" : cout << "False" ;
}