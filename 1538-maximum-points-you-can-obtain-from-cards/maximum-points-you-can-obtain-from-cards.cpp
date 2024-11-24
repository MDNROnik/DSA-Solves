class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans=0;
        int now=0;

        for(int i=0;i<k;i++){
            //cout<<now<<" "<<cardPoints[i]<<endl;
            now+=cardPoints[i];
        }
        ans=max(ans,now);
        int j =cardPoints.size();
        j-=1;
        //cout<<now<<endl<<endl;;
        cout<<j<<" "<<cardPoints[j]<<endl;
        k--;
        while(k>=0){
            now-=cardPoints[k];
            now+=cardPoints[j];
            ans=max(ans,now);
            k--;j--;
        }
        return ans;

    }
};