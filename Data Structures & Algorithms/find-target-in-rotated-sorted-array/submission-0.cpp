class Solution {
public:
    int maxelement(vector<int>& nums,int n)
    {
        int start = 0; int end = n-1;
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            int next = (mid+1)%n;
            int prev= (mid+n-1)%n;
            if(nums[mid]>nums[prev] and nums[mid]>nums[next])
                return mid;
            else if(nums[start]<=nums[mid])
                start = mid+1;
            else if(nums[mid]<=nums[end])
                end = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = maxelement(nums, n);
        int start = 0; int end = k;
        int res = -1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) start = mid+1;
            else end = mid-1;
        }
        start = k+1; end = n-1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) start = mid+1;
            else end = mid-1;
        }
        return res;
    }
};