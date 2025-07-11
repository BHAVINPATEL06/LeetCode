// class Solution {
// public:
//     // Tere bhai ne khud se kiya hai

//     // bool isSubsequenceMem(string& s, string& temp, int index1, int index2,
//     //                       vector<vector<int>>& dp) {
//     //     if (index1 == s.length() && index2 == temp.length())
//     //         return true;
//     //     if (index2 == temp.length())
//     //         return true;
//     //     if (index1 == s.length())
//     //         return false;
//     //     if (dp[index1][index2] != -1)
//     //         return dp[index1][index2];

//     //     bool ans = false;
//     //     if (s[index1] == temp[index2]) {
//     //         ans = true && isSubsequenceMem(s, temp, index1 + 1, index2 + 1, dp);
//     //     } else {
//     //         ans = false || (isSubsequenceMem(s, temp, index1 + 1, index2, dp) &&
//     //                         isSubsequenceMem(s, temp, index1, index2 + 1, dp));
//     //     }
//     //     dp[index1][index2] = ans;
//     //     return dp[index1][index2];
//     // }

//     int isSubsequenceTab(string &s, string &temp) {
//         vector<vector<bool>> dp(s.length()+1, vector<bool>(temp.length()+1, false));

//             for (int index1 = s.length()-1;index1 >= 0; index1--) {
//             for (int index2 = temp.length()-1; index2 >= 0; index2--) {
//                 if (s[index1] == temp[index2]) {
//                     dp[index1][index2] = true &&
//                           dp[index1 + 1][index2 + 1];
//                 } else {
//                     dp[index1][index2] = false ||
//                           (dp[index1 + 1][ index2]&&
//                            dp[index1][ index2 + 1]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }

//     int numMatchingSubseq(string s, vector<string>& words) {
//         int ans = 0;

//         for (int i = 0; i < words.size(); i++) {
//             vector<vector<int>> dp(s.length(),
//                                    vector<int>(words[i].length(), -1));
//             // if (isSubsequenceMem(s, words[i], 0, 0, dp))
//             //     ans++;
//             if(isSubsequenceTab(s,words[i]))
//                 ans++;
//         }

//         return ans;
//     }
// };

class Solution {
public:
    bool isSubsequence(string s1, string s2, int m, int n){
		//This function behaves simliar to the one in previous approach
        int j = 0;
        for(int i = 0; i < m && j < n; i++){
            if(s1[i] == s2[j]) j++;
        }
        return j == n;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
		
		//Hashmap with string and bool pair
		// Storing whether a string is subsequence or not!
        map<string, bool> mp;
        for(auto x: words){
		
			//if the string has already occurred then don't compute again
            if(mp.find(x) != mp.end()) {
				// if that string has value true that means it is subsequence, count++
                if(mp[x] == true) {
                    count++;
                }
				//if not, go for next string
                continue;
            }
			
			// if not calculated previously, compute the value and assign to x(current string from words)
            mp[x] = isSubsequence(s, x, s.size(), x.size());
            count += (mp[x] == true);
        }
		// return the final count of number of subsequences.
        return count;
    }
};