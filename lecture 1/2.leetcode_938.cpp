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


int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;
    if (low > root->val)
    {
        return rangeSumBST(root->right, low, high);
    }
    else if (high < root->val)
    {
        return rangeSumBST(root->left, low, high);
    }
    else
    {
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
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
    c->right=f;
    cout << rangeSumBST(a,7,15);
}