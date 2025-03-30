class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Handle empty input
        if (preorder.empty() || inorder.empty()) return nullptr;
        
        // Create hash map for inorder elements
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, 0, preorder.size() - 1,
                             inorder, 0, inorder.size() - 1, inMap);
    }
    
private:
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int, int>& inMap) {
        // Base case: if no elements to process
        if (preStart > preEnd) return nullptr;
        
        // Create root node from first element of preorder
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);
        
        // Find root position in inorder traversal
        int rootIndex = inMap[rootVal];
        
        // Calculate size of left subtree
        int leftSize = rootIndex - inStart;
        
        // Recursively build left and right subtrees
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftSize,
                                   inorder, inStart, rootIndex - 1, inMap);
        root->right = buildTreeHelper(preorder, preStart + leftSize + 1, preEnd,
                                    inorder, rootIndex + 1, inEnd, inMap);
        
        return root;
    }
};