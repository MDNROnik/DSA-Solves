class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>vs;
        int now = 0, size = target.size();
        for(int i=1;i<=n;i++){
            if(now<size){
                if(target[now] == i){
                    vs.push_back("Push");
                    now++;
                }
                else{
                    vs.push_back("Push");
                    vs.push_back("Pop");
                }
            }
            else{
                break;
            }
        }
        return vs;
    }
};