class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
      
        sort(skill.begin(),skill.end());
        int ptr1=skill.size()/2;
        int ptr2=ptr1-1;
        long long total=0;
        int sum=skill[ptr1]+skill[ptr2];
        while(ptr1<skill.size() && ptr2>=0){
            if(skill[ptr1]+skill[ptr2]!=sum){
                return -1;
            }
            total+=skill[ptr1++]*skill[ptr2--];
        }
        return total;
    }
    
};