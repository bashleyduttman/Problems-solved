class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int step=plants.size();
        int a=capacity;
        for(int i=0;i<plants.size();i++){
            if(capacity<plants[i]){
                step+=(i*2);
                capacity=a;

            }
           
                
            capacity-=plants[i];
            
        }
        return step;
    }
};