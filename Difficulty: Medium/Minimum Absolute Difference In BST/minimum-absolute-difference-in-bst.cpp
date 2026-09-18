/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/
class Solution {
public:
    void inorder(Node* root, vector<int>& v) {
        if(root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    int absDiff(Node* root) {
        vector<int> v;
        inorder(root, v);

        int ans = INT_MAX;

        for(int i = 1; i < v.size(); i++) {
            ans = min(ans, v[i] - v[i - 1]);
        }

        return ans;
    }
};