class Solution {
public:
    struct node {
        int height, index;
        node(int h, int i) : height(h), index(i) {}
    };
    int largestRectangleArea(vector<int> &height) {
        stack<node> s;
        s.push(node(-1, -1));
        int res = 0;
        for(int i = 0; i < height.size(); ++i) {
            if(height[i] > s.top().height) {
                s.push(node(height[i], i));
            } else if(height[i] < s.top().height) {
                int last = i;
                while(!s.empty() && height[i] < s.top().height) {
                    res = max(res, s.top().height * (i - s.top().index));
                    last = s.top().index;
                    s.pop();
                }
                s.push(node(height[i], last));
            }
        }
        while(!s.empty()) {
            res = max(res, s.top().height * ((int)height.size() - s.top().index));
            s.pop();
        }
        return res;
    }
};



class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int len=heights.size();
        int max_size=0;
        for(int i=0;i<len;i++)
        {
            int min_height=heights[i];
            int current_size=min_height;
            for(int j=i;j<len;j++)
            {
                if(heights[j]<min_height) min_height=heights[j];
                current_size=min_height*(j-i+1);
                if(current_size>max_size) max_size=current_size;
            }
        }
        return max_size;
    }
};