#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

Node* constructtree(string s, int &start)
{
    if(start >= s.size()) return NULL;
    start++;
    Node* head = new Node(s[start]-'0'); start++;
    if(start < s.size() && s[start] == ')') return head;

    head->left = constructtree(s, start); start++;
    if(start < s.size() && s[start] == ')') return head;

    head->right = constructtree(s, start); start++;
    if(start < s.size() && s[start] == ')') return head;

    return head;
}
int main()
{
    string str = "4(2(3)(1))(6(5))";
    //string str = "1(2)(3)";
    str = "(" + str + ")";

    int pos = 0;
    Node* root = constructtree(str, pos);
    preOrder(root);
    return 0;
}
