#include <algorithm>
#include <vector>
#include <iostream>

using  namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int n = static_cast<int>(nums.size());

    if(n == 0)
    {
        cout<<"return nullptr\n";
        return nullptr;
    }

    if(n == 1)
    {
        cout<<"return new TreeNode(nums[0])\n";
        return new TreeNode(nums[0]);
    }

    int low = 0;
    int high = n - 1;
    int mid = n / 2;

    TreeNode* node = new TreeNode(nums[mid]);
    cout<<"new_node = "<<nums[mid]<<endl;
    vector<int> left {};
    vector<int> right {};

    if(mid > low)
    {
        left.insert(left.begin(), nums.begin(), nums.begin() + mid);
        //for(int i = 0 ; i < mid ; i++)
        //{
        //    left.push_back(nums[i]);
        //}
    }

    if(mid < high)
    {
        right.insert(right.begin(), nums.begin() + mid + 1, nums.end());
        //for(int i = mid + 1 ; i < n ; i++)
        //{
        //    right.push_back(nums[i]);
        //}
    }

    //cout<<"left: ";
    //for(const auto& a : left)
    //{
    //    cout<<a<<" ";
    //}
    //cout<<"\nright: ";
    //for(const auto& a : right)
    //{
    //    cout<<a<<" ";
    //}
    //cout<<"\n";
    node->left = sortedArrayToBST(left);
    node->right = sortedArrayToBST(right);

    if(node->left)
    {
        cout<<"node->left = "<<node->left->val<<endl;
    }

    if(node->right)
    {
        cout<<"node->right = "<<node->right->val<<endl;
    }

    cout<<endl;
    return node;
}

int main()
{
    vector<int> v {-10,-3,0,5,9};
    sortedArrayToBST(v);

    return 0;
}
