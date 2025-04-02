class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int>ans;
        int n , m =arr.size();
        int i = 0;
        n=m;
        while(m>0){
            if(arr[m-1] == m){
                m--;continue;
            }
            int i=m-1;
            while(i--){
                if(arr[i] == m){
                    break;
                }
            }
            // cout<<i<<" "<<n<<endl;
            ans.push_back(i+1);
            reverse(arr.begin(), arr.begin()+i+1);
            // for(int j=0;j<n;j++){
            //     cout<<arr[j]<<" ";
            // }
            // cout<<endl;
            ans.push_back(m);
            reverse(arr.begin(), arr.begin()+m);
            // for(int j=0;j<n;j++){
            //     cout<<arr[j]<<" ";
            // }
            // cout<<endl<<endl;
            m--;
        }
        return ans;
    }
};