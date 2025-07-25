class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(int i = 0;i<s.length();i++){
            if(s[i] >= 'a' && s[i] <= 'z')ans.push_back(s[i]);

            if(s[i] == '*' && ans != "")ans.pop_back();

            if(s[i] == '#')ans = ans + ans;

            if(s[i] == '%')reverse(ans.begin(),ans.end());
        }

        return ans;
    }
};