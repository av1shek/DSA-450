/*
Note : Boundary level traversal is not same as right side view + left side view
+ bottom view

Also right traversal means rightest side layer, not right side view
Similary for left traversal

Also Bottom traversal means traversing all leafs from left to right or right to 
left, it is not same as bottom view.
*/

// recursive

class Solution {
public:
void leftBoundary(Node *root, vector<int> &ans)
{
    if(root==NULL) return;
     if(root->left==NULL && root->right==NULL) return;
    ans.push_back(root->data);
    if(root->left) leftBoundary(root->left, ans);
    else if(root->right) leftBoundary(root->right, ans);
}

void rightBoundary(Node *root, vector<int> &ans)
{
    if(root==NULL) return;
     if(root->left==NULL && root->right==NULL) return;
    if(root->right) rightBoundary(root->right, ans);
    else if(root->left) rightBoundary(root->left, ans);
    ans.push_back(root->data);
}

void leafNodes(Node *root, vector<int> &ans)
{
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }
    
    if(root->left) leafNodes(root->left, ans);
    if(root->right) leafNodes(root->right, ans);
}

vector <int> printBoundary(Node *root)
{
    vector<int> ans;
    
     if(root)  ans.push_back(root->data);
     if(root->left==NULL && root->right==NULL) return ans;
     if(root->left) leftBoundary(root->left, ans);
     leafNodes(root, ans);
     if(root->right) rightBoundary(root->right, ans);
     return ans;
}

};

// iterative

class Solution {
public:

vector <int> printBoundary(Node *root)
{
    vector<int> ans;
    
     if(root)  ans.push_back(root->data);
     if(root->left==NULL && root->right==NULL) return ans;
     Node *leftIt = root->left;
     Node *rightIt = root->right;
    
     // left Boundary
     while(leftIt && (leftIt->right!=NULL || leftIt->left!=NULL) )
     {
         ans.push_back(leftIt->data);
         if(leftIt->left) leftIt = leftIt->left;
         else if(leftIt->right) leftIt = leftIt->right;
     }
  
     // leaf Nodes - if you will do BFS then it leaves will not
     // comes in left to right order when leaves are at different level
     stack<Node*> s;
     while(!s.empty() || root)
     {
         while(root)
         {
             s.push(root);
             root = root->left;
         }
         
         root = s.top(); s.pop();
         if(root->right==NULL && root->left==NULL) ans.push_back(root->data);
         if(root->right) root = root->right;
         else root = NULL;
     }
    
     // right Boundary
     vector<int> temp;
     while(rightIt && (rightIt->right!=NULL || rightIt->left!=NULL) )
     {
         temp.push_back(rightIt->data);
         if(rightIt->right) rightIt = rightIt->right;
         else if(rightIt->left) rightIt = rightIt->left;
     }

     reverse(temp.begin(), temp.end());
     ans.insert(ans.end(), temp.begin(), temp.end());
     return ans;
}

};