
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
class Pair
{
public:
    long long mx;
    long long mi;
    bool flag;
    int size;
    Pair(long long mx, long long mi, bool flag, int size)
    {
        this->mx = mx;
        this->mi = mi;
        this->flag = flag;
        this->size = size;
    }
};
int maxsize = 0;
Pair valid(TreeNode *root)
{
    if (root == NULL)
        return {LLONG_MIN, LLONG_MAX, true, 0};
    Pair left = valid(root->left);
    Pair right = valid(root->right);
    int size = 1 + right.size + left.size;
    long long val = root->val;

    long long mx = max(val, max(left.mx, right.mx));
    long long mi = min(val, min(left.mi, right.mi));
    bool flag = (left.flag && right.flag &&
                 left.mx < val && val < right.mi);
    if (flag == true)
    {
        maxsize = max(maxsize, size);
    }
    return {mx, mi, flag, size};
}
int maxsizeBST(TreeNode *root)
{
    valid(root);
    return maxsize;
}
int main()
{
    vector<int> v;
    TreeNode *a = new TreeNode(10);
    TreeNode *b = new TreeNode(5);
    TreeNode *c = new TreeNode(15);
    TreeNode *d = new TreeNode(3);
    TreeNode *e = new TreeNode(7);
    TreeNode *f = new TreeNode(18);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;
}