class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(int i=0;i<emails.size();i++){
            string s=emails[i];
            string op;
            int j=0;
            while(s[j]!='@'){
                if(s[j]=='+'){
                    while(s[j]!='@'){
                        j++;
                    }
                    break;
                }
                else if(s[j]!='.'){
                    op.push_back(s[j]);
                }
                j++;
            }
            while(j<s.size()){
                op.push_back(s[j]);
                j++;
            }
            st.insert(op);
            
        }
        return st.size();
    }
};