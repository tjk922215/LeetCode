class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int length=nums.size();
        vector<vector<int> > result;
        int p=1<<length;
        for(int i=0;i<p;i++)
        {
            vector<int> tmp;
            //计算i中有那几位为1
            for(int j=0;j<length;j++)
            {
                //判断i中第j位是否为1
                int m=1<<j;
                if(i&m)
                {
                    tmp.push_back(nums[j]);
                }
            }
            result.push_back(tmp);
        }
        return result;
    }
};