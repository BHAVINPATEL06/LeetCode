class Solution {
public:
// Tere bhai ne khud se kiya hai
// Easily ho gya

    int minAddToMakeValid(string s) {
        stack<char>st;

        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                st.push('(');
            }
            else{
                if(!st.empty() && st.top() == '(' && s[i] == ')')st.pop();
                else if((s[i] == ')' && st.empty()) || (s[i] == ')' && st.top() == ')'))st.push(')');

            }
        }

        return st.size();
    }
};