
#include <iostream>
#include <climits>
#include <algorithm>
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
    int mx;
    int mi;

    Pair(int mx, int mi)
    {
        this->mx = mx;
        this->mi = mi;
    }

    friend ostream &operator<<(ostream &out, const Pair &p)
    {
        out << "Maximum: " << p.mx << endl;
        out << "Minimum: " << p.mi << endl;
        return out;
    }
};

// Find minimum and maximum values
Pair min_max(TreeNode *root)
{
    if (root == NULL)
        return {INT_MIN, INT_MAX};

    Pair left = min_max(root->left);
    Pair right = min_max(root->right);

    int mx = max(root->val, max(left.mx, right.mx));
    int mi = min(root->val, min(left.mi, right.mi));

    return {mx, mi};
}

// Find minimum value
int MinInTree(TreeNode *root)
{
    if (root == NULL)
        return INT_MAX;

    return min(root->val,
               min(MinInTree(root->left),
                   MinInTree(root->right)));
}

// Find maximum value
int MaxInTree(TreeNode *root)
{
    if (root == NULL)
        return INT_MIN;

    return max(root->val,
               max(MaxInTree(root->left),
                   MaxInTree(root->right)));
}

int main()
{
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

    cout << "Using Pair function:\n";
    cout << min_max(a);

    cout << "\nUsing separate functions:\n";
    cout << "Maximum: " << MaxInTree(a) << endl;
    cout << "Minimum: " << MinInTree(a) << endl;

    return 0;
}
