class Solution {
public:

    bool isPrime(int x){
        if(x == 0 || x == 1)return false;
        if(x == 2)return true;
        if(x%2 == 0)return false;
        
        for(int i = 3;i*i<=x;i+=2){
            if(x%i == 0)return false;
        }
        return true;
    }

    long long splitArray(vector<int>& nums) {
        long long sumA = 0;
        long long sumB = 0;

        for(int i = 0;i<nums.size();i++){
            if(isPrime(i))
                sumA+=nums[i];
            else
                sumB+=nums[i];
        }
        return abs(sumA-sumB);
    }
};