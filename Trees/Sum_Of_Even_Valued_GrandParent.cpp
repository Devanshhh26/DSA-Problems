// https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

/*

void evenVal(TreeNode* root, TreeNode* parent, TreeNode* grandparent, int& sum) {
    if (!root) {
        return;
    }

    if (grandparent && grandparent->val % 2 == 0) {
        sum += root->val;
    }

    evenVal(root->left, root, parent, sum);                     // update the parent with root and grandParent with the parent
    evenVal(root->right, root, parent, sum);
}

int sumEvenGrandparent(TreeNode* root) {
    int sum = 0;
    evenVal(root, nullptr, nullptr, sum);
    return sum;
}

*/