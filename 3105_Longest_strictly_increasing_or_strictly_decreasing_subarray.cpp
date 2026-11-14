class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int counter = 0;
        int max_inc = 0;
        int max_dec = 0;
        int idx = 1;

        int l = nums.size();

        if(l == 1) return 1;

        //increasing
        while(true)
        {
            if(idx == l) 
            {
                counter = 0;
                idx = 1;
                break;
            }
            
            if(nums[idx - 1] < nums[idx])
            {
                counter++;
            }
            if(nums[idx-1] < nums[idx] && (idx + 1 == l || nums[idx] >= nums[idx + 1]))
            {
                counter++;
                if(max_inc < counter)
                {
                    max_inc = counter;
                }
                counter = 0;
            }
            if(nums[idx - 1] == nums[idx])
            {
                counter++;
                if(max_inc < counter)
                {
                    max_inc = counter;
                }
                counter = 0;
            }
            idx++;
        }

        //decreasing
        while(true)
        {
            if(idx == l)
            {
                counter = 0;
                idx = 1;
                break;
            } 
            
            if(nums[idx - 1] > nums[idx])
            {
                counter++;
            }
            if(nums[idx-1] > nums[idx] && (idx+1 == l || nums[idx] <= nums[idx + 1]))
            {
                counter++;
                if(max_dec < counter)
                {
                    max_dec = counter;
                    //if(idx+1 == l) max_dec++;
                }
                counter = 0;
            }
            if(nums[idx - 1] == nums[idx])
            {
                counter++;
                if(max_dec < counter)
                {
                    max_dec = counter;
                }
                counter = 0;
            }
            idx++;
        }

        if(max_inc > max_dec) return max_inc;
        else return max_dec;

        
    }
};