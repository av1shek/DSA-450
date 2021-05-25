#include<bits/stdc++.h>
using namespace std;
typedef struct btnode *btptr;

struct btnode
{
    btptr lchild;
    char data;
    btptr rchild;

    btnode()
    {
        lchild = NULL;
        rchild = NULL;
    }
    btnode(char k)
    {
        lchild = NULL;
        data = k;
        rchild = NULL;
    }
};

void printInorder(btptr T)
{
    if(T == NULL)
        return;
    printInorder(T->lchild);
    cout<<T->data<<" ";
    printInorder(T->rchild);
    return;
}

int find(string s, char c, int low, int high)
{
    for(int i=low;i<=high;i++)
    {
        if(s[i]==c)
            return i;
    }
    return -1;
}

btptr buildTreeInPos(string inorder, string postorder, int low, int high, int &pos)
{
    if(low>high)
        return NULL;
    btptr T = new btnode(postorder[pos--]);
    if(low==high)
        return T;
    int i = find(inorder, T->data, low, high);
    T->rchild = buildTreeInPos(inorder, postorder, i+1, high, pos);
    T->lchild = buildTreeInPos(inorder, postorder, low, i-1, pos);
    return T;

}
btptr buildTreeInPos(string inorder, string postorder)
{
    int pos = inorder.size()-1, low = 0, high = inorder.size()-1;
    return buildTreeInPos(inorder, postorder, low, high, pos);
}
btptr buildTreeInPre(string inorder, string preorder, int low, int high, int &pos)
{
    if(low>high)
        return NULL;
    btptr T = new btnode(preorder[pos++]);
    if(low==high)
        return T;
    int i = find(inorder, T->data, low, high);
    T->lchild = buildTreeInPre(inorder, preorder, low, i-1, pos);
    T->rchild = buildTreeInPre(inorder, preorder, i+1, high, pos);
    return T;
}
btptr buildTreeInPre(string inorder, string preorder)
{
    int pos = 0, low = 0, high = inorder.size()-1;

    return buildTreeInPre(inorder, preorder, low, high, pos);
}


int main()
{
    string inorder = "123456789";
    string preorder = "531248679";
    string postorder = "214376985";
    btptr T = NULL;

	btptr T1 = buildTreeInPre(inorder, preorder);

    cout<<"Inorder :"<<endl;
    printInorder(T1); cout<<endl;
    return 0;
}
