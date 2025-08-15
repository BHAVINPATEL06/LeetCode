class Solution {
public:

    // Tere bhai ne khud se kiya hai
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int>nextGreater(height.size());
        vector<int>prevGreater(height.size());

        stack<int>st;
        st.push(-1);

        for(int i = height.size()-1;i>=0;i--){
            while(!st.empty() && st.top() != -1 && height[i]>=st.top())st.pop();
            nextGreater[i] = st.top();

            if(height[i]>st.top())
            st.push(height[i]);
        }

        stack<int>st2;
        st2.push(-1);

        for(int i = 0;i<height.size();i++){
            while(!st2.empty() && st2.top() != -1 && height[i]>=st2.top())st2.pop();
            prevGreater[i] = st2.top();

            if(height[i]>st2.top())
            st2.push(height[i]);
        }

        for(int i = 0;i<height.size();i++){
            if(nextGreater[i] != -1 && prevGreater[i] != -1){
                ans += abs(min(nextGreater[i],prevGreater[i])-height[i]);
            }
        }
        return ans;
    }
};