class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string stri = to_string(x);
        string stri2=stri;
        reverse(stri2.begin(), stri2.end());
        if(stri==stri2){
            return true;
        }
        else{
            return false;
        }

    }
};