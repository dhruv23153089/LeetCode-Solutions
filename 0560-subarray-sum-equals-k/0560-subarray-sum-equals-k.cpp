class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefixSum=0;
        unordered_map<int,int> mp;
        mp[0]=1;

        for(int r=0;r<nums.size();r++){
            prefixSum+=nums[r];
            int target = prefixSum -k;
            if(mp.find(target) !=mp.end()){
                count +=mp[target];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};