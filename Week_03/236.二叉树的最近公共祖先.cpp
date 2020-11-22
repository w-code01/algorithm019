class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		//如果 pp 和 qq 都存在，则返回它们的公共祖先；
		//如果只存在一个，则返回存在的一个；
		//如果 pp 和 qq 都不存在，则返回NULL
        if(root == NULL)
            return NULL;
        if(root == p || root == q) 
            return root;
            
        TreeNode* left =  lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
       
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;      
        if(left && right) // p和q在两侧
            return root;
        
        return NULL; // 必须有返回值
    }
};
