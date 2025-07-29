class Solution {
public:

    int mod = 1e9+7;
    int countHomogenous(string s) {
        int left = 0;
        int right = 0;  
        int ans = 0;


        while(right<s.length()){
            int count = 1;
            while(s[right] == s[right+1]){
                count++;
                right++;
            }
            
            for(int i= 1;i<=count%mod;i++){
                ans = (ans+i)%mod;
                ans = ans%mod;
            }
            right++;
        }
        return ans%mod;
    }
};