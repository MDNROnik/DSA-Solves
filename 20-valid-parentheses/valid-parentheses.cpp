class Solution {
public:
    bool isValid(string expression) {
            if(expression.size()%2!=0){
            return 0;
        }
        stack<char>s;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='('){
                s.push(expression[i]);
            }
            else if(expression[i]=='{'){
                s.push(expression[i]);
            }
            else if(expression[i]=='['){
                s.push(expression[i]);
            }
            else if(expression[i]==')' && s.size()>0 && s.top()=='('){
                s.pop();
            }
            else if(expression[i]=='}' && s.size()>0 && s.top()=='{'){
                s.pop();
            }
            else if(expression[i]==']' && s.size()>0 && s.top()=='['){
                s.pop();
            }
            else{
                s.push(expression[i]);
            }
        }
        //cout<<s.size()<<endl;
        if(s.size()==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};