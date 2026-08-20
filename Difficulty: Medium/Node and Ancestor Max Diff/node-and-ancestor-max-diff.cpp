/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
public:

    int solve(Node* root, int maxAncestor) {

        if (root == nullptr)
            return INT_MIN;

        int ans = maxAncestor - root->data;

        maxAncestor = max(maxAncestor, root->data);

        ans = max(ans, solve(root->left, maxAncestor));
        ans = max(ans, solve(root->right, maxAncestor));

        return ans;
    }

    int maxDiff(Node* root) {

        if (root == nullptr)
            return 0;

        return max(
            solve(root->left, root->data),
            solve(root->right, root->data)
        );
    }
};