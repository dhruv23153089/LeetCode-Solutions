class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums, k-1);
    }
    int atmost(vector<int>& nums,int k){
        int left=0;
        int ans=0;
        unordered_map<int, int> count;
        for(int right=0;right<nums.size();right++){
            count[nums[right]]++;

            while(count.size()>k){
                count[nums[left]]--;

                if(count[nums[left]]==0){
                    count.erase(nums[left]);
                }
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
};