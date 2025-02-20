class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s;
        find_ways(nums,nums[0].size(),s);
        return s;
    }
    int find_ways(vector<string> & nums,int size,string &s){
        if(s.size()==size){
            auto it=find(nums.begin(),nums.end(),s);
            if(it ==nums.end()){
                return 1;
            }
            return 0;
        }
        s.push_back('0');
        if (find_ways(nums,size,s)){
            return 1;
        }
        s.pop_back();
        s.push_back('1');
        if(find_ways(nums,size,s)){
            return 1;
        }
        s.pop_back();
        return 0;
    }
};