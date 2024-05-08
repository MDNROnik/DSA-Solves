class Solution {
public:
    string interpret(string command) {
        string s;
        for(int i=0;i<command.size();i++){
            //cout<<command[i]<<" "<<i;
            if(command[i]!='('){
                if(command[i]!=')'){
                    s.push_back(command[i]);
                }
            }
            if(command[i]=='(' && command[i+1]==')'){
                i++;
                s.push_back('o');
            }
        }
        return s;
    }
};