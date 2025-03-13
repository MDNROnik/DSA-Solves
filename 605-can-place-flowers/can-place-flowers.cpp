class Solution {
public:
    int fun(vector<int>& flower, int &size, int n, vector<vector<int>> &mp, int index){
        if(size<=index){
            if(n>0){
                return 1;
            }
            else{
                return 2;
            }
        }
        if(mp[index][n] != 0){
            return mp[index][n];
        }
        if(n<1){
            return 2;
        }
        if(flower[index]==1){
            return mp[index][n] = fun(flower, size, n, mp, index+1);
        }
        else{
            int take = 1, notTake = 1;

            if( (index-1>=0 && flower[index-1]==0) && (index+1<size && flower[index+1]==0) ){
                flower[index] = 1;
                take = fun(flower, size, n-1, mp, index+2);
                flower[index] = 0;
                if(take == 2){
                    return 2;
                }
            }
            else if( (index-1<0) && (index+1<size && flower[index+1]==0) ){
                flower[index] = 1;
                take = fun(flower, size, n-1, mp, index+2);
                flower[index] = 0;
                if(take==2){
                    return 2;
                }
            }
            else if( (index-1>=0 && flower[index-1]==0) && (index+1>=size ) ){
                flower[index] = 1;
                take = fun(flower, size, n-1, mp, index+2);
                flower[index] = 0;
                if(take == 2){
                    return 2;
                }
            }
            return mp[index][n] = fun(flower, size, n, mp, index+1);
        }
    }
    bool canPlaceFlowers(vector<int>& flower, int n) {
        int size = flower.size();
        if(size == 1){
            if(flower[0]==0 && n<=1){return true;}
            if(flower[0]==1 && n==0){return true;}
            return false;
        }
        for(int i=0;i<size;i++){
            if(flower[i]==0){
                int j=0;int count = 0;
                for(j=i;j<size;j++){
                    if(flower[j]==0){count++;}
                    else{
                        break;
                    }
                }
                if(i==0 && j==size){
                    if(count%2==0){
                        n-=(count/2);
                    }
                    else{
                        n-=(count/2);
                        n-=1;
                    }
                    break;
                }
                if(i==0){
                    cout<<count<<" "<<1<<endl;
                    count = count/2;
                    n-=count;
                }
                else if(j==size){
                    cout<<count<<" "<<2<<endl;
                    count = count/2;
                    n-=count;
                }
                else{
                    cout<<count<<" "<<3<<endl;
                    if(count>=3){
                        if(count%2==0){
                            n-=(count/3);
                        }
                        else{
                            n-=(count/2);
                        }
                    }
                }

                i=j;
            }
        }
        if(n<=0){return true;}
        else{
            return false;
        }
    }
};