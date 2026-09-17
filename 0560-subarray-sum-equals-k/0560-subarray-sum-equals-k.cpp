class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int l=0; l<nums.size();l++){
            int sum =0;
            for(int r=l; r<nums.size(); r++){
                sum += nums[r];
                if(sum == k){count++;}
            }
        }
        return count;
    }
};