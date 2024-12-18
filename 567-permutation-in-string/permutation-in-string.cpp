class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<vector<int>>v;
        map<char,int>mp;
        int k = s1.size();
        for(int i=0;i<k;i++){
            mp[s1[i]]++;
        }
        int m=s2.size()+2;
        for(int i=1;i<=28;i++){
            vector<int>vec(m,0);
            v.push_back(vec);
        }
        int n=s2.size();
        for(int i=0;i<n;i++){
            int ascii = s2[i];
            ascii-=96;
            //cout<<ascii<<endl;
            v[ascii][i+1]=1;
        }






        for(int i=0;i<28;i++){
            for(int j=1;j<v[i].size();j++){
                v[i][j]=v[i][j]+v[i][j-1];
            }
        }
        // for(int i=0;i<28;i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<v[i].size();j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        m=s1.size();
        int c= s1.size();
        int i=0;
        n=s2.size();
        while(m<n+2){
            //cout<<m<<" "<<n+2<<endl;
            int count=0;
            //cout<<m<<" "<<n<<endl;
            for(auto a=mp.begin();a!=mp.end();a++){
                int ascii = a->first;
                int att = a->second;
                //cout<<ascii<<" "<<att<<endl;
                ascii-=96;
                //cout<<v[ascii][m]-v[ascii][i] <<" inside "<<att<<endl;
                if( (v[ascii][m]-v[ascii][i]) == att ){
                    count+=att;
                }
                else{
                    break;
                }
            }
            cout<<count<<" "<<c<<endl;
            if(count==c){return true;}
            m++;i++;
        }
        
        
        return false;
    }
};