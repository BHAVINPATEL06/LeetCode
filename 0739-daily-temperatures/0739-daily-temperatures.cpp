class Solution {
public:
// Tere bhai ne khud se kiya hai
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size());
        stack<int>st;
        st.push(-1);

        for(int i = temperatures.size()-1;i>=0;i--){
            while(st.top() != -1 && !st.empty() && temperatures[st.top()]<=temperatures[i])st.pop();
            ans[i] = st.top();
            st.push(i);
        }
        for(int i = 0;i<ans.size();i++){
            if(ans[i]>0)ans[i] = ans[i]-i;
            else ans[i] = 0;
        }
        return ans;
    }
};