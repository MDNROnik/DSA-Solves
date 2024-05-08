class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int mini=0;
        int maxi=arr.size()-1;
        if(arr[0]>k){
            return k;
        }
        else if(arr[arr.size()-1]==arr.size()){
            return arr[arr.size()-1]+k;
        }
        while(mini<=maxi){
            int mid=mini+maxi;
            mid/=2;
            int now=arr[mid]-(mid+1);
            cout<<mini<<" "<<mid<<" "<<maxi<<endl;
            //cout<<now<<endl;
            if(now<k){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }
        }
        cout<<maxi<<endl;
        return arr[maxi] + (k-(arr[maxi]-(maxi+1)));
        return 1;
    }
};