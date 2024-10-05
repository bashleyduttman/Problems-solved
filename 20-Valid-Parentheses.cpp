class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='}' || s[i]==']' || s[i]==')'){
                char val;
                if(s[i]=='}'){
                    val='{';
                }
                else if(s[i]==']'){
                    val='[';
                }
                else{
                    val='(';
                }
                if(st.empty() || st.top()!=val ){
                    return false;
                    
                }
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size()==0;
    }
};