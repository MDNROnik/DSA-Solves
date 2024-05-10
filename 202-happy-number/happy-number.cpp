class Solution {
public:
    bool isHappy(int n) {
        map<int,bool>mp;
        while(1){
            int m=0;
            //cout<<n<<endl;
            while(n>0){
                int temp = n%10;
                temp=pow(temp,2);
                m+=temp;
                n/=10;
            }
            n=m;
            if(m==1){
                return true;
            }
            if(mp[m]==false ){
                mp[m]=true;
            }
            else{
                //cout<<m<<endl;
                return false;
            }
        }
        return true;
    }
};