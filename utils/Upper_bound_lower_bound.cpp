#include <bits/stdc++.h>
using namespace std;
/* upper bound of k in nums is equal to the first index such that nums[index] > k*/
/* this code will return the last element index if k > nums[end-1]*/
/* in case the k is smaller than the nums[0] then 0 is returned which is also correct.*/

int upper_bound(vector<int>& nums, int k) {
    
    int n = nums.size();
    if(nums[n-1] <= k){
        /* upper bound does not exist */
        return -1;
    }

    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    /* high + 1 because it is giving one index lesser everytime.*/
    return high +1;
}


/* lower_bound of k means the first index where the arr[index]>=k */
/* in case all elements in arr are strictly smaller than k returns -1.*/
/* othwise returns the lower_bound for k.*/
int lower_bound(vector<int>& nums, int k) {
    
    int n = nums.size();
    if(nums[n-1] < k){
        /* lower bound does not exist */
        return -1;
    }

    int low = 0, high = nums.size()-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
    vector<int> nums{1,2,3,3,4};

    cout<<upper_bound(nums,0)<<endl;
    cout<<upper_bound(nums,4)<<endl;
    cout<<upper_bound(nums,5)<<endl;
    return 0;
}