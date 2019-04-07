//by liuxin,17.4.20
class Solution {
    
public:
    int removeDuplicates(vector<int>& nums) 
    {
        
        int len=nums.size();
        
        int lind,rind;
        lind=rind=0;
        
        while(lind<len-1)
        {
            rind=lind+1;
                
                //只可能相邻元素出现重复
                if(nums[lind]==nums[rind])
                {
                    //出现重复,删除该元素
                nums.erase(nums.begin()+lind);//waste time here!!
                len--;

                }else{
                //相邻元素不等，后面也不会再出现跟lind所在元素重复的元素
                lind++;

                }
        }
        
    return len;
    }
    
    
    
};