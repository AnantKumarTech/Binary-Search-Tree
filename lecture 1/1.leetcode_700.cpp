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
    v.push_back(root->val);
    preorder(root->left, v);
    preorder(root->right, v);
}
vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> v;
    preorder(root, v);
    return v;
}
TreeNode *searchBST(TreeNode *root, int val)
{
    if(root==NULL) return NULL;
    if(root->val<val){
      return searchBST(root->right,val);
    }
    else if (root->val > val){
        return searchBST(root->left,val);
    }
    return root;
}
int main()
{
    vector<int> v;
    TreeNode *a = new TreeNode(4);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(7);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(3);
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;

    TreeNode *ans=searchBST(a,2);
    v = preorderTraversal(ans);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}