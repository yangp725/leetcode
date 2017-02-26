#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        
        int v;
        while (!que.empty()) {
        	TreeNode* r = que.front();  // access the first element
        	que.pop();  // removes the first element
        	if (r->right)
        		que.push(r->right);
        	if (r->left)
        		que.push(r->left);
        	v = r->val;
		}
		return v;
    }
};

int main () {
    return 0;
}
