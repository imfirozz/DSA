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
}; */

class Solution {
public:
    // Helper to find LCA of two nodes (by value)
    Node* findLCA(Node* root, int p, int q) {
        if (!root) return nullptr;
        if (root->data == p || root->data == q) return root;

        Node* left = findLCA(root->left, p, q);
        Node* right = findLCA(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    // Helper to get path directions from root to target node
    bool getPath(Node* root, int target, vector<char>& path) {
        if (!root) return false;
        if (root->data == target) return true;

        path.push_back('L');
        if (getPath(root->left, target, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

    int numberOfTurns(Node* root, int p, int q) {
        if (p == q) return -1;   // same node, no path

        Node* lca = findLCA(root, p, q);

        vector<char> pathP, pathQ;
        getPath(lca, p, pathP);   
        getPath(lca, q, pathQ);   

        // Build full movement sequence: p → LCA → q
        vector<char> full;
        // Up from p to LCA: reverse of pathP
        for (int i = pathP.size() - 1; i >= 0; --i)
            full.push_back(pathP[i]);
        // Down from LCA to q
        for (char c : pathQ)
            full.push_back(c);

        // Count adjacent direction changes
        int turns = 0;
        for (int i = 0; i + 1 < full.size(); ++i) {
            if (full[i] != full[i + 1])
                turns++;
        }

        // If no direction changed, return -1
        return (turns == 0) ? -1 : turns;
    }
};