class Solution
{
    public: 
    void solve(Node *root, Node* &curr)
    {
        if(root==NULL) return;
        Node *l = root->left;
        Node *r = root->right;
        
        solve(l, curr);
        curr->right = root;
        root->left = curr;
        curr = curr->right;
        solve(r, curr);
    }
.
    Node * bToDLL(Node *root)
    {
        Node* head = newNode(0);
        Node* curr = head;
        solve(root, curr);
        head = head->right;
        head->left = NULL;
        return head;
    }
};
// to inorder and store prev node, to point