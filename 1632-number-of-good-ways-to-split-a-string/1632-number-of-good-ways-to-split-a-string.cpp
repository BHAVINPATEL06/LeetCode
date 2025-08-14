class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mapp;
        unordered_map<char,int>mapp2;

        for(int i = 0;i<s.length();i++){
            mapp[s[i]]++;
        }

        int i = 0;
        int j = 1;
        int ans = 0;

        while(i<s.length()){
            mapp2[s[i]]++;
            mapp[s[i]]--;
            if(mapp[s[i]] == 0)mapp.erase(s[i]);
            if(mapp2.size() == mapp.size())ans++;
            i++;
        }
        return ans;
    }
};