class Solution {
public:
    string makeFancyString(string s) {
            int count = 0;
            string ans = "";
        
        for(int i = 0;i<s.length();i++){
            char ch = s[i];
            if(s[i] == s[i+1]){
                count++;
            }else{
                count = 0;
            }
            if(count >= 2){
                s[i] = '#';
            }
            
        }

        int i = 0;
        int j = s.length();

        while(i<j){
            if(s[i]!='#'){
                ans.push_back(s[i]);
            }
            i++;
        }

    return ans;
    }
};