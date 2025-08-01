class Solution {
public:

    void solve(string &digits,string &temp,vector<string>&ans,int index,unordered_map<int,string>&phone){
        if(index == digits.length()){
            if(temp.length()>0){
                ans.push_back(temp);
            }
            return;
        }

        string mapString = phone[digits[index]-'0'];
        for(auto a: mapString){
            temp.push_back(a);
            solve(digits,temp,ans,index+1,phone);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>phone;
        phone[2] = "abc";
        phone[3] = "def";
        phone[4] = "ghi";
        phone[5] = "jkl";
        phone[6] = "mno";
        phone[7] = "pqrs";
        phone[8] = "tuv";
        phone[9] = "wxyz";


        vector<string>ans;
        string temp;
        int n = digits.length();
        solve(digits,temp,ans,0,phone);
        return ans;
    }
};