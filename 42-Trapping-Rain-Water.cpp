class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMax(height.size()),suffixMax(height.size());
        prefixMax[0]=height[0];
        int total=0;
        int n=height.size();
        suffixMax[height.size()-1]=height[height.size()-1];       
        for(int i=1;i<height.size();i++){
            prefixMax[i]=max(prefixMax[i-1],height[i]);
            suffixMax[n-i-1]=max(suffixMax[n-i],height[n-i-1]);

        }
       
        for(int i =0;i<height.size();i++){
            if(prefixMax[i]>height[i] && suffixMax[i]>height[i]){
                total+=min(prefixMax[i],suffixMax[i])-height[i];
            }
        }
        return total;
    }
};