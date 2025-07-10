class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        int left = 0;
        int ans = 0;
        set<char>sett;

        while(right<s.length()){
            char ch = s[right];

            if(sett.find(ch) == sett.end()){
                sett.insert(ch);
                int size = sett.size();
                ans = max(ans,size);
                right++;
            }
            else{
                while(s[left] != ch){
                    sett.erase(s[left]);
                    left++;
                }
                left++;
                right++;
            }
        }
        return ans;
    }
};