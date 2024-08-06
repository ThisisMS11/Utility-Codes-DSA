#include <bits/stdc++.h>
using namespace std;

long long int ReturnSubarraysXor(vector<int>&arr){
    int n = arr.size();

    long long int answer = 0;

    /* Now we will try to find out for each bit , what is the number of subarrays that have the xor of all of its element with ith bit set */

    for(int bit=0;bit<32;++bit){

        int no_of_subarrays = 0;

        /* This loop will help us figure out the the number of subarrays that have the xor of all of its element with ith bit set starting from j=0*/

        bool hasOddSetBits = false;
        for(int j=0;j<n;++j){
            if(arr[j] & (1<<bit))
                hasOddSetBits = !hasOddSetBits;
            
            if(hasOddSetBits)
                ++no_of_subarrays;
        }

        /* Now so far no_of_subarrays just represents subarrays with starting from j=0 but inorder to find all the subarrays we have to traverse all items yet again*/
        for(int j=0;j<n;++j){
            answer += ((1<<bit) * no_of_subarrays);

            if(arr[j] & (1<<bit)){
                /* Now we are moving away from j so it will for sure affect the number of subarrays,. Now listen. All the subarrays which could not come into play because of arr[j] starting from j+1 (because it was making the count of elements with ith bit set even for them) should now be consider */

                /*subarrays that failed to satisfy from j+1 (will now satisfy)= total_subarrays from j - no_of_subarrays that satisfied from j*/
                no_of_subarrays = (n-j) - no_of_subarrays;
            }
        }
    }

    return answer;
}

int main()
{
    vector<int> arr{1, 3, 7, 9, 8, 7};
    cout<<ReturnSubarraysXor(arr)<<endl;
    return 0;
}
