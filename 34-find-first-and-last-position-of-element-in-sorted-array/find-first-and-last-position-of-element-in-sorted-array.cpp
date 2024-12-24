class Solution {
public:
    int lowerBound(vector<int> &arr, int n, int x) {
        int ans=n;
        int i=0,j=n-1;
        while(i<=j){
            int mid=i+j;
            mid/=2;
            if(arr[mid]>=x){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        if(ans==n){ans--;}
        return ans;
    }
    int upperBound(vector<int> &arr, int n, int x){
		int ans=n;
		int i=0,j=n-1;
		if(arr[0]>x){
			return 0;
		}
		else if(arr[n-1]<=x){
			//cout<<1111<<" "<<n<<endl;
			return n;
		}
		while(i<=j){
			int mid=i+j;
			mid/=2;
			
			if(arr[mid]<=x){
				i=mid+1;
			}
			else if(arr[mid]>x){
				ans=mid;
				j=mid-1;
			}
			
		}
		return ans;	
	}
    vector<int> searchRange(vector<int>& v, int target) {
        
        vector<int>ans;
        if(v.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;   
        }
        int lower = lowerBound(v,v.size(),target);
        int upper = upperBound(v,v.size(),target);

        cout<<lower<<" "<<upper<<endl;
        if(v[lower]==target){
            ans.push_back(lower);
            ans.push_back(upper-1);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }      
        return ans;
    }
};