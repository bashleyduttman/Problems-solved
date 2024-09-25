class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        vector<long long> prefix_arr;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            prefix_arr.push_back(sum);
            sum+=nums[i];
        }
        long long mini=LLONG_MAX;
        prefix_arr.push_back(sum);
        deque<long long> d_queue;
        for(int i=0;i<prefix_arr.size();i++){
            while(!d_queue.empty() && prefix_arr[i]-prefix_arr[d_queue.front()]>=k){
                mini=min(mini,i-d_queue.front());
                d_queue.pop_front();
            }
            while(!d_queue.empty() && prefix_arr[i]<=prefix_arr[d_queue.back()]){
                d_queue.pop_back();
            }
            d_queue.push_back(i);
        }
        if(mini==INT_MAX){
            return -1;
        }
        return mini;
    }
};