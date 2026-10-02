class Solution {
public:
    string longestPalindrome(string s) {
        int start=0; int end=0;

        for(int i=0; i<s.size(); i++){
            int odd = expand(s,i,i);
            int even = expand(s,i,i+1);
            int len = max(odd,even);

            if(len > (end-start)){
                start = i - (len-1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end-start+1);
    }


private: 
    int expand(string s, int l,int r){
        while(l>=0 && r<s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
};