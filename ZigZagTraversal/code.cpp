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


    //post order traversal using two stacks 
    vector<int> postOrderTraversal(Node* root){
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        stack<Node*> st1,st2;
        st1.push(root);
        while(st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != NULL){
                st1.push(root->left);
            }
            if(root->right != NULL){
                st1.push(root->right);
            }
            while(!st2.empty()){
                postOrder.push_back(st2.top()->data);
                st2.pop();
            }
        }
        return postOrder;
    }


    //postorder traversal using one stack
    vector<int> postOrderTraversal1(Node* root){
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        stack<Node*> st;
        st.push(root);
        while(root != NULL || !st.empty()){
            if(root != NULL){
                st.push(root);
                root = root->left;
            }
            else {
                Node* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                    while (!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->data);
                    }
                } else root =temp;
            }
        }
        return postOrder;
    }

    vector<vector<int>> preInPostOrderTraversal(Node* root){
        if(root == NULL) return {};
        stack<pair<Node*,int>> st;
        st.push({root,1});
        vector<int> pre,in,post;
        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it.second == 1){
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->left != NULL){
                    st.push({it.first->left,1});
                }
            } else if(it.second == 2){
                in.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->right != NULL){
                    st.push({it.first->right,1});
                }
            } else {
                post.push_back(it.first->data);
            }
        }
        return {pre,in,post};
    }

    int maxDepthBT(Node *root){
        if(root == NULL) return 0;

        int lh = maxDepthBT(root->left);
        int rh = maxDepthBT(root->right);

        return 1+max(lh,rh);
    }

    int dfsHeight(Node *root){
        if(root == NULL) return 0;

        int lh = dfsHeight(root->left);
        if(lh == -1) return -1;
        int rh = dfsHeight(root->right);
        if(rh == -1) return -1;

        if(abs(lh-rh)>1) return -1;

        return 1+max(lh,rh);
    }

    //checking for balance Binary Tree

    bool isBalancedBinaryTree(Node* root){
        return dfsHeight(root) != -1;
    }


    //Diameter of Binary Tree
    int maxDepthBTDiameter(Node *root,int diameter){
        if(root == NULL) return 0;

        int lh = maxDepthBT(root->left);
        int rh = maxDepthBT(root->right);
        diameter = max(diameter,lh+rh);

        return 1+max(lh,rh);
    }

    int diameterofBinaryTree(Node* root){
        int diameter = 0;
        diameter = maxDepthBTDiameter(root,diameter);
        return diameter;
    }

    int maxPath(Node* root,int maxi){
        if(root == NULL) return 0;

        int left = max(0,maxPath(root->left,maxi));
        int right = max(0,maxPath(root->right,maxi));

        maxi = max(maxi,left+right+root->data);
        return max(left,right)+root->data;
    }

    int maxSum(Node* root){
        int maxi = 0;
        maxi = maxPath(root,maxi);
        return maxi;
    }

    ///check if tree are identical or not 

    bool sameTree(Node* p,Node* q){
        if(p==NULL || q==NULL) return (p==q);
        return (p->data == q->data) && sameTree(p->left , q->left)
        && sameTree(p->right , q->right);
    }



    //Zig Zag Traversal
    vector<vector<int>> zigZagTraversal(Node* root){
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row;
            for(int i{0};i<size;i++){
                Node* node = nodesQueue.front();
                nodesQueue.pop();
                int index = (leftToRight) ? i : (size-1-i);
                row[index] = node->data;

                if(node->left){
                    nodesQueue.push(node->left);
                }

                if(node->right){
                    nodesQueue.push(node->right);
                }

            }

            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
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

    cout << "The height of Binary Tree is: " << root1->maxDepthBT(root1) << endl;

    cout << boolalpha;
    cout << root->isBalancedBinaryTree(root)<<endl;

    cout <<root1->diameterofBinaryTree(root1) << endl;

    cout << root1->maxSum(root1) << endl;

    cout << root1->sameTree(root1,root) << endl; //false because both trees are not same

    vector<vector<int>> result;
    result = root1->zigZagTraversal(root1);

    for(auto it: result){
        for(auto i: it){
            cout << i << " ";
        }
        cout << endl;
    }
    //pre,in,post order traversals
    // vector<int> ans = {2,3,6,7,9};
    // vector<int> ans1 = {1,4,8,10};
    // cout << median(ans,ans1,4) << endl;
    return 0;
}