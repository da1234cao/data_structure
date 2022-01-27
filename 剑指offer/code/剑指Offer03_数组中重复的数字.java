import java.util.Vector;

class Solution {
    public int findRepeatNumber(int[] nums) {
        int[] count = new int[nums.length];
        int result = -1;
        for(int i=0; i<nums.length; i++){
            count[nums[i]]++;
            if(count[nums[i]] >=2 ){
                result = nums[i];
                break;
            }
        }
        return result;
    }
}