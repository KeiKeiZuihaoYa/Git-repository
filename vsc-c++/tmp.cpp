#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *root;

vector<int> v;
int dfs(TreeNode *x)
{
    if (x == nullptr)
        return 0;

    int left = -1, right = -1;
    if (x->left != nullptr)
        left = dfs(x->left);
    if (x->right != nullptr)
        right = dfs(x->right);

    if (left == right)
    {
        v.push_back(left + right + 1);
        return left + right + 1;
    }
    else
    {
        v.push_back(-1);
        return -1;
    }
}
int kthLargestPerfectSubtree(TreeNode *root, int k)
{
    dfs(root);
    sort(v.begin(), v.end(), less<int>());
    for (auto i : v)
        cout << i << ' ';
    return v[k];
}

void build(TreeNode *&now)
{
    int tmp;
    cin >> tmp;
    if (tmp = -1)
        return;
    else
    {
        now = new TreeNode;
        now->val = tmp;
        build(now->left);
        build(now->right);
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    build(root);
    int k;
    cin >> k;
    cout << kthLargestPerfectSubtree(root, k);
    return 0;
}
