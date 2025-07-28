class Solution {
public:
    bool rotateString(string s, string goal) {
        int rotations = s.length();

        while(rotations--){

            char ch = s[0];
            for(int i = 1;i<s.length();i++){
                s[i-1] = s[i];
            }
            s[s.length()-1] = ch;

            if(s == goal)return true;
        }
        return false;
    }
};