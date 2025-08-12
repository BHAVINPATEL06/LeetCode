class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;

        int i = 0;
        int j = 0;

        while(i<nums1.size() && j < nums2.size()){
            int element1 = nums1[i][0];
            int element2 = nums2[j][0];

            if(element1 == element2){
                ans.push_back({element1,nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(element1 > element2){
                ans.push_back({element2,nums2[j][1]});
                j++;
            }
            else if(element1 < element2){
                ans.push_back({element1,nums1[i][1]});
                i++;
            }
        }

        while(i<nums1.size()){
            ans.push_back({nums1[i][0],nums1[i][1]});
            i++;
        }
        while(j<nums2.size()){
            ans.push_back({nums2[j][0],nums2[j][1]});
            j++;
        }

        return ans;
    }
};