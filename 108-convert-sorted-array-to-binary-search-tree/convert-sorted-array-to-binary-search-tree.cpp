/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* fun(vector<int>& nums, int i, int j){

        
        int mid = i+j;
        mid/=2;
        int n = nums.size(); 
        cout<<i<<" "<<" "<<j<<endl;
        if(mid==nums.size() || j<i ){
            //cout<<111<<endl;
            return NULL;
        }
        else if(i==j){
            return new TreeNode(nums[i]);
        }

        TreeNode* newn = new TreeNode(nums[mid]);
        newn->left = fun(nums,i,mid-1);
        newn->right = fun(nums,mid+1,j);

        return newn;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        int m=n/2;
        TreeNode* head = new TreeNode( nums[m] );

        head->left = fun(nums,0,m-1);
        head->right = fun(nums,m+1,n-1);

        return head;
    }
};