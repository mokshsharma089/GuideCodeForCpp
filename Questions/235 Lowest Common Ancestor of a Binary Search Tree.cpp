235. Lowest Common Ancestor of a Binary Search Tree
Medium
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia:
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants
(where we allow a node to be a descendant of itself).”

Example 1-
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.

Example 2-
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.


ALGO-
Way 1
Do normally like you would in binary tree

Way 2 - Optimize for BST
## Hint LCA would be the first element whose value is in between both the elements while traversing top to bottom
1. traverse from top to bottom
2. check if my value is in b/w the values or equal to any then i am lca. condition==> {(p->val) <= (root->val) <= (q->val) }
3. if my value if greater than both the values then ans(lca) would be in left sub tree call for that
4. else ans would be in right subtree call for that




Code-
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(p->val<q->val){
           return helper(root,p,q);
       }
       else{
           return helper(root,q,p);
       }
       return NULL;

   }
   TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
       if(root==NULL){
           return NULL;
       }
       if(root==p){
           return p;
       }
       if(root==q){
           return q;
       }
       if(root->val>=p->val and root->val<=q->val){
           return root;
       }
       if(root->val>p->val and root->val>q->val){
           return helper(root->left,p,q);
       }
       if(root->val<p->val and root->val<q->val){
           return helper(root->right,p,q);
       }
       return NULL;
   }
};



TC-O(h) worst case N
SC-O(h) worst case N
