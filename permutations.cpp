class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        int length=num.size();
        int k=fac(length);
        vector<vector<int>> result;
        sort(num.begin(),num.end());
        for(int i=0;i < k; i++){
            vector<int> visited(num);
            vector<int> temp;
            int p=i;
            for(int j = length-1;j > 0;j --){
                int m=p/fac(j);
                temp.push_back(visited[m]);
                visited.erase(visited.begin()+m);
                p%=fac(j);
            }
            temp.push_back(visited[0]);
            result.push_back(temp);
        }
        return result;
    }
private:
    int fac(int n){
        int num = 1;
        for (int i = 1; i < n + 1; ++i)
            num *= i;
        return num;
    }
};