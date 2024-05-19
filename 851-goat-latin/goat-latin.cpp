class Solution {
public:
    string toGoatLatin(string s) {
        int n=s.size();
        int count=0;
        string x;
        string str;
        for (int i=0;i<n;i++) { 
            if(s[i]==' '){
                count++;
                //cout<<x<<endl;
                if(tolower(x[0])=='a' || tolower(x[0])=='e' || tolower(x[0])=='i' || tolower(x[0])=='o' || tolower(x[0])=='u'){
                    //cout<<111<<endl;
                    for(int j=0;j<x.size();j++){
                        str.push_back(x[j]);
                    }
                    str.push_back('m');
                    str.push_back('a');
                    int c=0;
                    while(c<count){
                        str.push_back('a');
                        c++;
                    }
                }
                else{
                    for(int j=1;j<x.size();j++){
                        str.push_back(x[j]);
                    }
                    str.push_back(x[0]);
                    str.push_back('m');
                    str.push_back('a');
                    int c=0;
                    while(c<count){
                        str.push_back('a');
                        c++;
                    }
                }
                str.push_back(' ');
                x="";
            }
            else{
                x.push_back((s[i]));
            } 
            
        }
        count++;
        //cout<<x<<endl;
        if(tolower(x[0])=='a' || 
           tolower(x[0])=='e' || 
           tolower(x[0])=='i' || 
           tolower(x[0])=='o' || 
           tolower(x[0])=='u'){
            //cout<<111<<endl;
            for(int j=0;j<x.size();j++){
                str.push_back(x[j]);
            }
            str.push_back('m');
            str.push_back('a');
            int c=0;
            while(c<count){
                str.push_back('a');
                c++;
                }
        }
        else{
            for(int j=1;j<x.size();j++){
                str.push_back(x[j]);
            }
            str.push_back(x[0]);
            str.push_back('m');
            str.push_back('a');
            int c=0;
            while(c<count){
                str.push_back('a');
                c++;
            }
        }
        
        return str;
    }
};