103. Binary Tree Zigzag Level Order Traversal
Medium

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

       3      left to right
      / \
     09  20    right To left
         /\
        15 07   left to right


Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []

ALGORITHM
1. Do normal level order traversal just maintain a bool flag to see if we have to go left to right or vice versa
2. In one direction, add to front of temp vector and for other direction add from the back
3. Dont push right first and left second because then it would give wrong answer and save wrong state.

CODE-
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool dir=false;
        while(!q.empty()){
            vector<int> temp;
            int len=q.size();
            while(len--){
                TreeNode* curr=q.front();
                q.pop();
                if(dir){
                    temp.insert(temp.begin(),curr->val);
                }
                else{
                    temp.push_back(curr->val);
                }
                if(curr->left){
                        q.push(curr->left);
                    }
                if(curr->right){
                        q.push(curr->right);
                    }
            }
            if(dir==true){
                dir=false;
            }
            else{
                dir=true;
            }
            ans.push_back(temp);
        }
        return ans;
    }

TC-O(N) traverse tree once
SC-O(N) maintain a queue 
