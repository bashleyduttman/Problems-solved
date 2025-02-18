
class Solution {
public:
    string smallestNumber(string pattern) {
        unordered_set<int> st;
        string ans="zzzzzzzzzzzzz";
        string temp;
        

        for (int i = 1; i <= 9; i++) {
            st.insert(i);
            temp.push_back(i + '0');  
            backtrack(pattern, 0, st, temp, ans);
            temp.pop_back();
            st.erase(i);
        }
        return ans;
    }

    void backtrack(string &pattern, int ind, unordered_set<int>& st,
                     string& temp, string &ans) {
        if (ind == pattern.size()) {

            ans = min(ans,temp);
            return;
        }

        for (int i = 1; i <= 9; i++) {
            if (st.find(i) == st.end()) {
                if (pattern[ind] == 'I' && (temp.back() - '0' < i)) {
                    st.insert(i);
                    temp.push_back(i + '0');
                    backtrack(pattern, ind + 1, st, temp, ans);
                    temp.pop_back();
                    st.erase(i);
                } 
                else if (pattern[ind] == 'D' && (temp.back() - '0' > i)) {
                    st.insert(i);
                    temp.push_back(i + '0');
                    backtrack(pattern, ind + 1, st, temp, ans);
                    temp.pop_back();
                    st.erase(i);
                }
            }
        }
    }
};

