class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(s.length()<p.length()) return res;

        unordered_map<int, int> pMap, sMap;
        for(char c:p){
            pMap[c]++;
        }

        int left=0, count=p.length();

        for(int right=0; right<s.length(); right++){
            char ch = s[right];
            sMap[ch]++;

            if(pMap.count(ch) && sMap[ch]<=pMap[ch]){
                count--;
            }
            if(right - left +1 >p.length()){
                char leftChar = s[left];
                if(pMap.count(leftChar) && sMap[leftChar] <= pMap[leftChar]){
                    count++;
                }
                sMap[leftChar]--;
                left++;
            }
            if(count == 0){
                res.push_back(left);
            }
        }
        return res;
    }
};