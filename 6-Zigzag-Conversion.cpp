class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> vec(numRows);
        if(numRows==1){
            return s;
        }
        bool down=false;
        int ind=0;
        for(int i=0;i<s.size();i++){
            vec[ind]+=s[i];
            if(ind==0 || ind==numRows-1){
                down=!down;
            }
            ind+=down?1:-1;
        }
        string n;
        for(int i=0;i<vec.size();i++){
            n+=vec[i];
        }
        return n;
    }
};