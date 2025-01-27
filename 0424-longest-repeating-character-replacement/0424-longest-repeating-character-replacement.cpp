class Solution {
public:
    int characterReplacement(string s, int k) {
        int r=0,l=0,maxCount=0,maxLen=0;
        int n = s.size();
        int hash[26] ={0};

        while(r<n){
            hash[s[r] -'A']++;
            maxCount = max(maxCount,hash[s[r]-'A']);

            if((r-l+1) -maxCount > k){
                hash[s[l] -'A']--;
                l++;
            }

            maxLen = max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};