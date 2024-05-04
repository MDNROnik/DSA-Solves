class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int credit=1;
        for(int i=0;i<digits.size();i++){
            int dig = digits[i];
            credit+=dig;
            dig = credit%10;
            credit/=10;
            digits[i]=dig;
        }
        if(credit>0){
            digits.push_back(credit);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};