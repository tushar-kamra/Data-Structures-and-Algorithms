#include<iostream>
#include<queue>
#include<stack>
#include<deque>

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

void spiralorder(Node* root){
    deque<Node*> dq ;
    dq.push_front(root) ;
    bool r2l = true ;
    while(!dq.empty()){
        int n = dq.size() ;
        while(n--){
            Node* temp = NULL ;
            if(r2l){
                temp = dq.back() ;
                dq.pop_back() ;
                if(temp->right) dq.push_front(temp->right) ;
                if(temp->left) dq.push_front(temp->left) ;
            }
            else {
                temp = dq.front() ;
                dq.pop_front() ;
                if(temp->left) dq.push_back(temp->left) ;
                if(temp->right) dq.push_back(temp->right) ;
            }
            cout << temp->data << " " ;
        }
        r2l = !r2l ;
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
    root = insertNode(root,11);
    root = insertNode(root,9);
    root = insertNode(root,3);
    spiralorder(root) ;
}