class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxArea = 0;
        while(i<j)
        {
          int w = j - i;
          int h = min(height[i],height[j]);
          int area = w * h;
          maxArea = max (maxArea , area);
          if(height[i]<height[j])
          {
            i++;
          }
          else
          {
            j--;
          }
        }
        return maxArea;
    }
};
