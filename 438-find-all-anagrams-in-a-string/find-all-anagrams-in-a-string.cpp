class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        vector<vector<int>>vec(30, vector<int>(n+10, 0));
        vector<int>ans;
        for(int i=0;i<n;i++){
            int ascii = s[i]-97;
            vec[ascii][i+1]++;
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<=n;j++){
                vec[i][j]+=vec[i][j-1];
            }
        }

        int m=p.size();
        vector<int>v(30, 0);

        for(int i=0;i<m;i++){
            int ascii = p[i]-97;
            v[ascii]++;
        }


        // for(int i=0;i<26;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<vec[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=m;i<=n;i++){
            int count= 0;
            // cout<<i-m<<" START "<<i<<endl;
            for(int j=0;j<26;j++){
                // cout<<vec[j][i] <<" "<< vec[j][i-m]<<endl;
                int c = vec[j][i] - vec[j][i-m];
                int require = v[j];
                // cout<<c<<" -- "<<require<<endl;
                if(c >= require){
                    count++;
                }
                else{
                    break;
                }
            }
            // cout<<count<<" LAST "<<m<<endl;
            if(count==26){
                // cout<<" IN "<<endl;
                ans.push_back(i-m);
            }
        }

        return ans;
    }
};