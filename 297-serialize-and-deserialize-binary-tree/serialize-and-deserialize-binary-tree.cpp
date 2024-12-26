/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void fun1(TreeNode* root, string &ans){
        if(root==nullptr){
            ans.append(" 1001");
            return;
        }
        stringstream str1;
        str1 << root->val;
        string geek = str1.str();
        ans.append(" ");
        ans.append(geek);

        fun1(root->left, ans);
        fun1(root->right, ans);
        return;
    }

    string serialize(TreeNode* root) {
        string ans;
        fun1(root, ans);
        //cout<<ans<<endl;
        return ans;
    }
    TreeNode* fun2(string &data, int &index, int &n){
        string ans ="";
        cout<<index<<" "<<data[index]<<endl;
        for(;index<n;index++){
            if(data[index]==' '){
                break;
            }
            else{
                ans.push_back(data[index]);
            }
        }
        stringstream geek;
        geek << ans;
        int x = 0;
        geek >> x;
        index=index+1;
        if(x==1001){
            return nullptr;
        }
        //cout<<x<<" "<<data[index]<<" "<<index<<endl;
        TreeNode* node = new TreeNode(x);
        node->left = fun2(data, index, n);
        node->right = fun2(data, index, n);
        return node;
    }
    TreeNode* deserialize(string data) {
        cout<<data<<endl;
        data.erase(data.begin() + 0);
        TreeNode* ans ;
        
        int n=data.size();
        int index=0;
        ans = fun2(data, index, n);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));