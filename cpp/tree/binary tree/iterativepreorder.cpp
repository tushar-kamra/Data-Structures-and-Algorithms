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

void postorder(Node* root){
    if(root == NULL){
        return ;
    }
    postorder(root->left);
    postorder(root->right) ;
    cout << root->data << " " ;
}

// Method 1
void iterpreorder1(Node* root){
    stack<Node*> s ;
    while(true){
        while(root){
            s.push(root) ;
            cout << root->data <<" " ;
            root = root->left ;
        }
        if(s.empty()){
            break ;
        }
        root = s.top();
        s.pop();
        root = root->right ;
    }
}

// Method 2
void iterpreorder2(Node* root){
    stack<Node*> s ;
    s.push(root) ;
    while(!s.empty()){
        root = s.top();
        cout << root->data <<" " ;
        s.pop() ;
        if(root->right){
            s.push(root->right) ;
        }
        if(root->left){
            s.push(root->left) ;
        }
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
    cout << "Preorder Recursive : " ;
    preorder(root) ;
    cout << endl ;
    cout << "Preorder Iterative 1 : " ;
    iterpreorder1(root) ;
    cout << endl ;
    cout << "Preorder Iterative 2 : " ;
    iterpreorder2(root) ;
    cout << endl ;
}