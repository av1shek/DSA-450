int minValue(Node* root)
{
    Node *curr = root;
    while(curr->left)
        curr = curr->left;
    return curr->data;
}