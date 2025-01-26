class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        int totalGas=0, totalCost=0, latest=-1;
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for(int i=0;i<n;i++){
            totalGas+=gas[i];
            totalCost+=cost[i];
            if(totalGas<totalCost){
                latest=i;
            }
        }
        if(totalGas<totalCost){
            return -1;
        }
        latest=0;
        int gg=0, cc=0, pre=-1;
        for(int i=0;i<n;i++){
            gg+=gas[i], cc+=cost[i];
            if(gg<cc || (pre==i-1 && gg>cc)){
                cout<<i<<endl;
                pre=i;
                int g=0, c=0, now=0;
                for(int j=i;j<n;j++){
                    g+=gas[j];
                    c+=cost[j];
                    if(g<c){
                        now++;break;
                    }
                }
                if(now==1){continue;}
                for(int j=0;j<i;j++){
                    g+=gas[j];
                    c+=cost[j];
                    if(g<c){
                        now++;break;
                    }
                }
                if(now==1){continue;}
                if(now==0){
                    latest=i;break;
                }
            }
        }
        int i=n-1;
        while(i<n){
            int g=0, c=0, now=0;
            for(int j=i;j<n;j++){
                g+=gas[j];
                c+=cost[j];
                if(g<c){
                    now++;break;
                }
            }
            if(now==1){i++;continue;}
            for(int j=0;j<i;j++){
                g+=gas[j];
                c+=cost[j];
                if(g<c){
                    now++;break;
                }
            }
            if(now==1){i++;continue;}
            if(now==0){
                latest=i;break;
            }
            
        }
        return latest;
    }
};