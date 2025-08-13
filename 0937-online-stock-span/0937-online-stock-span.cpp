class StockSpanner {
public:
    // Tere bhai ne khud se kiya hai
    // Vishwas nhi hoga liken khud se kiya hai
    
        stack<int>st;
        vector<int>nums;
        vector<int>ans;
        int index = -1;

    StockSpanner() {
        st.push(-1);

    }

    int next(int price) {
        nums.push_back(price);

        for(int i = index+1;i<nums.size();i++){
            while(!st.empty() && st.top() != -1 && nums[i]>=nums[st.top()]){
                st.pop();
            }
            ans.push_back(abs(st.top()-index)+1);
            st.push(i);
        }
        index++;
        return ans[index];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */