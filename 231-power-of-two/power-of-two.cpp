class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        if(n<=0){
            return 0;
        }
while(n!=0){
    if( (n&1)!=0 ){
        count++;
    }
   n>>=1;
}
if(count==1){
    return 1;
}
else{
    return 0;
}

    }
};