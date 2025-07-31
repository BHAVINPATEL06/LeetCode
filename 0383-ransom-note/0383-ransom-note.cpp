class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mapp;
        for(int i = 0;i<magazine.length();i++){
            mapp[magazine[i]]++;
        }

        unordered_map<char,int>mapp2;
        for(int i = 0;i<ransomNote.length();i++){
            mapp2[ransomNote[i]]++;
        }

        for(int i = 0;i<ransomNote.length();i++){
            if(mapp[ransomNote[i]]< mapp2[ransomNote[i]] || mapp.find(ransomNote[i]) == mapp.end()){
                return false;
            }
        }
        return true;
    }
};