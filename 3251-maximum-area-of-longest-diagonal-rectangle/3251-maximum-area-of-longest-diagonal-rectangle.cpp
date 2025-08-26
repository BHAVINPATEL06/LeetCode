class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double ans = 0;
        double prev = 0;
        for(int i = 0;i<dimensions.size();i++){
            double l = dimensions[i][0];
            double w = dimensions[i][1];

            if(sqrt(l*l+w*w)>prev){
                ans = l*w;
                prev = sqrt(l*l+w*w);
            }
            else if(sqrt(l*l+w*w) == prev){
                ans = max(ans,l*w);
                prev = sqrt(l*l+w*w);
            }
        }
        return (int)ans;
    }
};