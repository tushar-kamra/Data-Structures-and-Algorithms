#include<iostream>
#include<queue>
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

void deleteDeepest(Node* root, Node* delNode){
    queue<Node*> q ;
    q.push(root) ;
    while(!q.empty()){
        Node* temp = q.front() ;
        q.pop() ;
        if(temp == delNode){
            temp = NULL ;
            delete delNode ;
            return ;
        }
        if(temp->right){
            if(temp->right == delNode){
                temp->right = NULL ;
                delete delNode ;
                return ;
            }
            else {
                q.push(temp->right) ;
            }
        }
        if(temp->left){
            if(temp->left == delNode){
                temp->left = NULL ;
                delete delNode ;
                return ;
            }
            else {
                q.push(temp->left) ;
            }
        }
    }
}

Node* deleteNode(Node* root, int x){
    if(root == NULL){
        return root;
    }
    if(root->left == NULL && root->right == NULL){
        if(root->data == x){
            return NULL ;
        }
        return root ;
    }
    queue<Node*> q ;
    q.push(root) ;
    Node* temp ;
    Node* deleteNode = NULL ;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == x){
            deleteNode = temp ;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    if(deleteNode != NULL){
        deleteNode->data = temp->data ;
        deleteDeepest(root,temp) ;
    }
    return root ;
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
    cout << "Preorder : " ;
    preorder(root) ;
    cout << endl ;
    cout << "Inorder : " ;
    inorder(root) ;
    cout << endl ;
    cout << "Postorder : " ;
    postorder(root) ;
    cout << endl ;

    root = deleteNode(root,2) ;

    cout << endl ;
    cout << "Preorder : " ;
    preorder(root) ;
    cout << endl ;
    cout << "Inorder : " ;
    inorder(root) ;
    cout << endl ;
    cout << "Postorder : " ;
    postorder(root) ;
    cout << endl ;
}