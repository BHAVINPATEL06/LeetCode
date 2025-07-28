class Solution {
public:

    void reConvert(string &s){
        char start = 'a';
        unordered_map<char,int>mapp;
        for(int i = 0;i<s.length();i++){
            if(mapp.find(s[i]) == mapp.end()){
                mapp[s[i]] = start;
                start++;
            }
        }

        for(int i = 0;i<s.length();i++){
            s[i] = mapp[s[i]];
        }
    }

    bool isIsomorphic(string s, string t) {
        reConvert(s);
        reConvert(t);

        return s == t;
    }
};