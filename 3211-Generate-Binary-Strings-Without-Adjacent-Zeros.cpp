class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> arr;
        
    valids(n,arr,"");
    return arr;

    }
    void valids(int n,vector<string> & arr,string s){
        if(n==0){
            arr.push_back(s);
            return  ;
        }
        s+='1';
        valids(n-1,arr,s);
        s.pop_back();
        if(s.empty() || s[s.size()-1]!='0'){
            s+='0';
            valids(n-1,arr,s);
            s.pop_back();

        }
       

    }
};