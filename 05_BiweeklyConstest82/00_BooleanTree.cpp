// https://leetcode.com/contest/biweekly-contest-82/problems/evaluate-boolean-binary-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (root -> left == nullptr) return root->val;
        if (root->val == 2) return evaluateTree(root->left) || evaluateTree(root->right);
        else return evaluateTree(root->left) && evaluateTree(root->right);      
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}