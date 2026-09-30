class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        while(left < right){
            if(s[left] != s[right]){
                return isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1);
            }
            left++;
            right--;
        }
        return true;
    }
    
private: 
    bool isPalindrome(string &s, int l ,int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};


