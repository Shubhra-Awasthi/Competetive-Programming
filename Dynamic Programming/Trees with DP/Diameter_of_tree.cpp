
int res;

int diameterOfBinaryTree(TreeNode *root)
{
    res = 0;
    solve(root);
    return res - 1; // edges number
}

int solve(TreeNode *root)
{
    if (!root)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int temp = 1 + max(l, r); // not in ans
    int ans = 1 + l + r;      // in ans

    res = max(res, ans);
    return temp;
}
