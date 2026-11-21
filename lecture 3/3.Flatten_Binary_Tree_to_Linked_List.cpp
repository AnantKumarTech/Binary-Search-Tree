
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
void flatten(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            // find predecessor
            TreeNode *pred = curr->left;
            while (pred->right and pred->right != curr)
            {
                pred = pred->right;
            }
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
            

        }
        else
        {
          
            curr = curr->right;
        }
    }
}
int main()
{
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    a->left = b;
    a->right = d;
    b->left = c;
    b->right = e;
    d->left = f;
    //   cout<<a->val<<endl;
    //   cout<<a->left->val<<endl;
    //   cout<<a->left->left->val<<endl;
    //   cout<<a->right->val<<endl;
    //   cout<<a->left->right->val<<endl;
    //   cout<<a->right->left->val<<endl;
}