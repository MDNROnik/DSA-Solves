class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //sort(bills.begin(),bills.end());
        int five=0, ten=0, tw=0, ans = 0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            int re = bills[i]-5;
            if( ( (ten*10)+(five*5)+(tw*20) ) >= re ){
                cout<<five<<" IN "<<ten<<" "<<tw<<endl;
                //20
                int note = re/20;
                if(tw>=note){
                    int remain = re-(note*20);
                    tw-=note;
                    re=remain;
                }
                else{
                    re-=(tw*20);tw=0;
                }
                //10
                note = re/10;
                if(ten>=note){
                    int remain = re-(note*10);
                    ten-=note;
                    re=remain;
                }
                else{
                    re-=(ten*10);ten=0;
                }

                //5
                note = re/5;
                if(five>=note){
                    int remain = re-(note*50);
                    five-=note;
                    re=remain;
                }
                else{
                    re-=(five*5);five=0;
                }

                if(re>0){
                    return false;
                }
                if(bills[i]==5){five++;}
                else if(bills[i]==10){ten++;}
                else{
                    tw++;
                }
                cout<<five<<" OUT "<<ten<<" "<<tw<<endl;
            }
            else{
                return false;
            }
        }
        return true;
    }
};