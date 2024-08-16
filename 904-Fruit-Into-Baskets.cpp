class Solution {
public:
    int totalFruit(vector<int>& fruits) {
         int l=0,r=0,maxi=0,track=0,element;
         unordered_set<int> non_dup;
         while(r<fruits.size())
         {
            
            non_dup.insert(fruits[r]);
            if(non_dup.size()>2)
            {
                l=track;
                non_dup.erase(element);
            }
            maxi=max(maxi,r-l+1);
            if(r>0 && fruits[r]!=fruits[r-1]){
                element=fruits[r-1];
                track=r;
            }
           
            r+=1;
            
         }
         return maxi;
        
    }
};