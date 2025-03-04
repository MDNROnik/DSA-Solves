class Solution {
public:

bool checkPalindrome(string s)
{
    int i=0;int j=s.size()-1;
    while(i<=j){
        if(s[i]==s[j]){
            i++;j--;
        }
        else{
            return false;
        }
    }
    return true;
}
    void fun( string &s, string &a, string &b, int indexi, int indexj, int &n, int &ans, int index){
        if(index==n){
            if(checkPalindrome(a) && checkPalindrome(b)){
                ans = max(ans, (  indexi*indexj  ));
            }
            return ;
        }

        //take by a
        a.push_back(s[index]);
        fun(s, a, b, indexi+1, indexj, n, ans, index+1);
        a.pop_back();

        //take by 
        b.push_back(s[index]);
        fun(s, a, b, indexi, indexj+1, n, ans, index+1);
        b.pop_back();

        //not take
        fun(s, a, b, indexi, indexj, n, ans, index+1);
    }
    int maxProduct(string s) {
        string a="", b="";
        int indexi=0, indexj=0;
        int n=s.size();
        int ans=0;
        fun(s, a, b, indexi, indexj, n, ans, 0);
        return ans;
    }
};