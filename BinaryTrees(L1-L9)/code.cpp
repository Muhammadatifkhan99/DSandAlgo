#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

struct Node{
    int data;

    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = NULL;
    }

    void preOrder(Node *root){
        if(root == NULL) return;

        cout << root->data << "->";
        preOrder(root->left);
        preOrder(root->right);

    }

    void inOrder(Node *root){
        if(root == NULL) return;

        inOrder(root->left);
        cout << root->data << "->";
        inOrder(root->right);

    }

    void postOrder(Node *root){
        if(root == NULL) return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << "->";

    }

    //BFS Traversal

    vector<vector<int>> levelOrder(Node *root){
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i{0};i<size;i++){
                Node* root = q.front();
                q.pop();
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
                level.push_back(root->data);
            }
            ans.push_back(level);
        }
        return ans;
    }

    //Iterative Traversals

    vector<int> preOrderTraversal(Node* root){
        vector<int> preOrder;
        if(root==NULL) return preOrder;
        stack<Node*>st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preOrder.push_back(root->data);
            //as we have stack so we will be following the LIFO rules so to get the left most value first we pushed the right first
            if(root->right != NULL) st.push(root->right);
            if(root->left  != NULL) st.push(root->left);

        }
        return preOrder;
    }

    ///Iterative Inorder Traversal
    vector<int> inorderTraversal(Node *node){
        vector<int> inOrder;
        Node* root = node;
        stack<Node*>st;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            } else {
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->data);
                node = node->right;
            }
        }
        return inOrder;
    }
};          


int main(){

    //###################################################################
    cout<<"Play ground is up and running" << endl;
    //###################################################################

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(7);
    root->left->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);
    root->right = new Node(7);

    root->preOrder(root);
    cout << endl;
    root->inOrder(root);
    cout << endl;
    root->postOrder(root);
    root->levelOrder(root);

    //preOrder Traversals
    cout << endl;
    vector<int> traversal = root->preOrderTraversal(root);
    for(auto it: traversal){
        cout << it << "->    ";
    }
    cout << endl;

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(6);
    root1->left->right->right = new Node(7);

    //inorderTraversals
    vector<int> traversal1 = root1->inorderTraversal(root1);
    for(auto it: traversal1){
        cout << it << "->";
    }
    cout << endl;

    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}