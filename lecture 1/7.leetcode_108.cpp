
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
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    if (nums.empty())
    {
        return NULL;
    }

    int low = 0;
    int high = nums.size() - 1;

    int mid = (low + high) / 2;

    TreeNode *head = new TreeNode(nums[mid]);

    vector<int> a, b;

    for (int i = 0; i < mid; i++)
    {
        a.push_back(nums[i]);
    }

    for (int i = mid + 1; i <= high; i++)
    {
        b.push_back(nums[i]);
    }

    head->left = sortedArrayToBST(a);
    head->right = sortedArrayToBST(b);

    return head;
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