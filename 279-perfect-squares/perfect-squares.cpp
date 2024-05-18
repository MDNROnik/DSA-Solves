class Solution {
public:
    int fun(int n,vector<int> &vec){
        //cout<<n<<endl;
        if(n==0){
            // for(int i=0;i<v.size();i++){
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
            return 1;
        }
        else if(n<0){
            return INT_MAX;
        }
        else if(vec[n]!=-1){
            return vec[n];
        }
        int sum = INT_MAX;
        for(int i=1;;i++){
            int p=pow(i,2);
            if(p>n){
                break;
            }
            // v.push_back(p);
            int temp = fun(n-p,vec);
            sum=min(sum,temp);
            // v.pop_back();
        }
        sum+=1;
        vec[n]=sum;
        return vec[n];
    }
    int numSquares(int n) {
        int ans=0;
        vector<int>v;
        vector<int>vec;
        for(int i=0;i<=10005;i++){
            vec.push_back(-1);
        }
        return fun(n,vec)-1;
    }
};