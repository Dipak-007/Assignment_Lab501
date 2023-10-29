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

/*
    Zig-Zag Traversal
            1
          /   \
         2     4
        / \     \
       3   5     7
          / \     \
         6   8     9
                  / \
                 10  11

    Output
    1
    4 2
    3 5 7
    9 8 6
    10 11
*/

//function for Zig-Zag Traversal
void zigZagLevelOrder(TreeNode* root){
    if(root){
        vector<int> ans;
        queue<TreeNode*> q;
        bool left=true;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(!temp){
                if(!left){
                    for(int i=ans.size()-1;i>=0;i--)     cout<<ans[i]<<" ";
                    left=true;
                }
                else{
                    for(int i:ans)  cout<<i<<" ";
                    left=false;
                }
                cout<<"\n";
                ans.clear();
                if(!q.empty())  q.push(nullptr);
            }
            else{
                ans.emplace_back(temp->val);
                if(temp->left)  q.push(temp->left);
                if(temp->right)  q.push(temp->right);
            }
        }
    }
}

/*
    Boundary Traversal
            1
          /   \
         2     4
        / \     \
       3   5     7
          / \     \
         6   8     9
                  / \
                 10  11

    Output
    1 2 3 6 8 10 11 9 7 4
*/

//sub functions for boundary traversals
void traverseLeft(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right) return;
        ans.emplace_back(root->val);
        if(root->left) traverseLeft(root->left,ans);
        else traverseLeft(root->right,ans);
    }
}

void traverseLeaves(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right){
            ans.emplace_back(root->val);
            return;
        }
        traverseLeaves(root->left,ans);
        traverseLeaves(root->right,ans);
    }
}

void traverseRight(TreeNode* root,vector<int> &ans){
    if(root){
        if(!root->left && !root->right) return;
        if(root->right) traverseRight(root->right,ans);
        else traverseRight(root->left,ans);
        ans.emplace_back(root->val);
    }
}

//function for boundary traversal
void BoundaryOrder(TreeNode* root){
    if(root){
        vector<int> ans;
        ans.emplace_back(root->val);
        traverseLeft(root->left,ans);
        traverseLeaves(root->left,ans);
        traverseLeaves(root->right,ans);
        traverseRight(root->right,ans);
        for(int i:ans)  cout<<i<<" ";
    }
}

/*
    Diagonal Traversal
            1
          /   \
         2     3
        / \   / \
       4   5  6  7
      / \    /    \
     8   9  10    11


    Output              key
    1 3 7 11             0
    2 5 6                1
    4 9 10               2
    8                    3

    Approach
    A key is given to each node such that
        - Left node key = 1 + root node key
        - Right node key = root node key
*/

void solve(TreeNode* root,int key,map<int,vector<int>> &ans){
    if(root){
        ans[key].emplace_back(root->val);
        solve(root->left,key+1,ans);
        solve(root->right,key,ans);
    }
}

//function for diagonal traversal
void diagonalTraversal(TreeNode *root) {
    map<int,vector<int>> ans;
    solve(root,0,ans);
    for(auto i:ans){
        for(int j=0;j<i.second.size();j++)
            cout<<i.second[j]<<" ";
        cout<<"\n";
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
        cout<<"5. Zig-Zag Traversal\n";
        cout<<"6. Boundary Traversal\n";
        cout<<"7. Diagonal Traversal\n";
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
            case 5: cout<<"\nZigZag Traversal -->\n";
                    zigZagLevelOrder(root);
                    break;
            case 6: cout<<"\nBoundary Traversal -->\n";
                    BoundaryOrder(root);
                    break;
            case 7: cout<<"\nDiagonal Traversal -->\n";
                    diagonalTraversal(root);
                    break;
            default:cout<<"\nQuitting...";
                    flag=false;
        }
    }
    
    return 0;
}
