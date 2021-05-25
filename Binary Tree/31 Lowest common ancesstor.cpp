TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
{
        
    if (root == NULL) return NULL;
    if (root == p  root == q)
    return root;

    TreeNode left_lca  = lowestCommonAncestor(root-left, p, q);
    TreeNode right_lca = lowestCommonAncestor(root-right, p, q);

    if (left_lca && right_lca)  return root;
    return (left_lca != NULL) left_lca right_lca;
}