
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
void myNode(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    else if (root->val > val)
    {
        myNode(root->left, val);
    }
    else
    {
        myNode(root->right, val);
    }
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    myNode(root, val);
    return root;
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