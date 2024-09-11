class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l=0,r=arr.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid]==target){
                return true;
            }
            if(arr[mid]==arr[l] && arr[mid]==arr[r]){
                l++;
                r--;
                continue;
            }
            if(arr[l]<=arr[mid]){
                if(arr[l]<=target && arr[mid]>=target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }

            }
            else{
                if(arr[mid]<=target && arr[r]>=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return false;
    }
};