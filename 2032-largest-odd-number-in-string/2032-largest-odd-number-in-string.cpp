class Solution {
public:
    string largestOddNumber(string num) {
        
        int index = 0;
        for(int i = num.length()-1;i>=0;i--){
            int digit = num[i]-'0';
            if(digit&1){
                return num.substr(0,num.length()-index);
            }
            index++;
        }
        return "";
    }
};