// 1) From any node to any node: https://leetcode.com/problems/binary-tree-maximum-path-sum/
int res;

int maxPathSum(TreeNode *root)
{
    res = INT_MIN;
    solve(root);
    return res;
}

int solve(TreeNode *root)
{
    if (!root)
        return 0;

    int l = max(0, solve(root->left));  // take or no take
    int r = max(0, solve(root->right)); // take or no take

    int temp = root->val + max(l, r); // not ans root
    int ans = root->val + l + r;      // ans root
    res = max(res, ans);

    return temp;
}

// 2) From leaf to leaf: https://www.geeksforgeeks.org/problems/maximum-path-sum/1

long long res;

long long maxPathSum(Node *root)
{
    res = LLONG_MIN;

    long long ans = solve(root);

    return (res == LLONG_MIN) ? max(ans, res) : res;
}

long long solve(Node *root)
{
    if (!root)
        return LLONG_MIN;
    if (!root->left && !root->right)
        return root->data; // leaf

    long long l = solve(root->left);
    long long r = solve(root->right);

    long long temp = root->data + max(l, r);

    // 2 children
    if (l != LLONG_MIN && r != LLONG_MIN)
    {
        long long ans = root->data + l + r;
        res = max(res, ans);
    }

    return temp;
}
