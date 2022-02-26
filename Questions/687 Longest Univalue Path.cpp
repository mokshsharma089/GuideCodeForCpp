687. Longest Univalue Path
Medium

Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value.
This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

Example 1:
Input: root = [5,4,5,1,1,5]
Output: 2

Example 2:
Input: root = [1,4,5,4,4,5]
Output: 2

TC-O(N)
SC-O(N)

Code-
class dp{
    public:
    int maxLen;
    int currLen;
    int val;
    bool fromNull;
};
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        dp a=helper(root);
        return a.maxLen;
    }
    dp helper(TreeNode* root){
        dp a;
        if(root==NULL){
            a.fromNull=true;
            a.maxLen=INT_MIN;
            return a;
        }
        a.val=root->val;
        a.fromNull=false;
        dp left=helper(root->left);
        dp right=helper(root->right);
        //both children are NULL
        if(left.fromNull and right.fromNull){
            a.currLen=0;
            a.maxLen=0;
             cout<<"\n at root value = "<<root->val<<" currlen returned "<<a.currLen<<" maxLen returned "<<a.maxLen;
            return a;
        }
        int tempLen=0;//checks of we get the maxLen with root and its children only
        int dir=0;//tells which direction was the largest and should be connected if parents value is also found to be same
        if(!left.fromNull){
            if(left.val==root->val){
                tempLen+=left.currLen+1;
                dir=max(dir,left.currLen+1);
            }
        }
        if(!right.fromNull){
            if(right.val==root->val){
                tempLen+=right.currLen+1;
                dir=max(dir,right.currLen+1);
            }
        }
        a.maxLen=max(tempLen,max(left.maxLen,right.maxLen));
        a.currLen=dir;
        cout<<"\n at root value = "<<root->val<<" currlen returned "<<a.currLen<<" maxLen returned "<<a.maxLen;
        return a;
    }
};
