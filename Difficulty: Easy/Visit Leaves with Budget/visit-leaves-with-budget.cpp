/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:

    void solve(Node* root, int level, vector<int>& leaves) {

        if(root == NULL)
            return;

        // Leaf node
        if(root->left == NULL && root->right == NULL) {
            leaves.push_back(level);
            return;
        }

        solve(root->left, level + 1, leaves);
        solve(root->right, level + 1, leaves);
    }

    int getCount(Node* root, int k) {

        vector<int> leaves;

        // Root is at level 1
        solve(root, 1, leaves);

        sort(leaves.begin(), leaves.end());

        int ans = 0;

        for(int cost : leaves) {

            if(k < cost)
                break;

            k -= cost;
            ans++;
        }

        return ans;
    }
};