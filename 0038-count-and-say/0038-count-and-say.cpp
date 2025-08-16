class Solution {
public:
    // Tere bhai ne khud se kiya hai
    // Question samaj na tha bass baki toh easy tha
    string countAndSay(int n) {
        if(n == 1)return "1";

        string temp = countAndSay(n-1);
        string ans = "";

        int count = 1;
        for(int i = 0;i<=temp.length()-1;i++){
            if(temp[i] == temp[i+1]){
                count++;
            }
            else{
                ans.push_back(count+'0');
                ans.push_back(temp[i]);
                count = 1;
            }
        }
        return ans;
    }
};