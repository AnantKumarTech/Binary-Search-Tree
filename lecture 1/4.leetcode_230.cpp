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
void preorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }

    preorder(root->left, v);
    v.push_back(root->val);
    preorder(root->right, v);
}
int kthSmallest(TreeNode *root, int k)
{
    vector<int> v;
    preorder(root, v);
    return v[k - 1];
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