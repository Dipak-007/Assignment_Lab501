#include<bits/stdc++.h>
using namespace std;

//structure of node of a tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//function to create a tree
TreeNode* createTree(){
    int x;
    cout<<" Enter Data (-1 for NULL) : ";
    cin>>x;
    if(x==-1)   return nullptr;
    TreeNode *temp=new TreeNode(x);
    cout<<"Left of "<<x;
    temp->left=createTree();
    cout<<"Right of "<<x;
    temp->right=createTree();
    return temp;
}

//function for inorder Traversal
void inorder(TreeNode *root){
    if(root){
        inorder(root->left);
        cout<<root->val<<" ";
        inorder(root->right);
    }
}

//function for preorder Traversal
void preorder(TreeNode *root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

//function for postorder Traversal
void postorder(TreeNode *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        cout<<root->val<<" ";
    }
}

//function for Level Order Traversal
void levelOrder(TreeNode *root){
    if(!root)   return;
    queue<TreeNode*> q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        TreeNode *temp=q.front();
        q.pop();
        if(!temp){
            cout<<"\n";
            if(!q.empty())  q.push(nullptr);
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    TreeNode *root=createTree();
    int opt;
    int flag=true;
    while(flag){
        cout<<"\n\nWhich Traversal you want to perform on the Tree?\n";
        cout<<"1. Inorder Traversal\n";
        cout<<"2. Preorder Traversal\n";
        cout<<"3. Postorder Traversal\n";
        cout<<"4. Level Order Traversal\n";
        cout<<"\nPress any other number to quit...";
        cin>>opt;

        switch(opt){
            case 1: cout<<"\nInorder Traversal -->  ";
                    inorder(root);
                    break;
            case 2: cout<<"\nPreorder Traversal -->  ";
                    preorder(root);
                    break;
            case 3: cout<<"\nPostorder Traversal -->  ";
                    postorder(root);
                    break;
            case 4: cout<<"\nLevel Order Traversal -->\n";
                    levelOrder(root);
                    break;
            default:cout<<"\nQuitting...";
                    flag=false;
        }
    }
    
    return 0;
}
