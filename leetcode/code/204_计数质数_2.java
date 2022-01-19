import java.net.InetAddress;
import java.util.Vector;

class Solution {
    private Vector<Integer> primer_nums = new Vector<Integer>();
    
    public int countPrimes(int n) {
        if(n<=2) // 0和1的质数为零。题目限定n为非负整数
            return 0;

        primer_nums.add(2); // 2为质数，放入
        for(int i=3; i<n; i++){
            int size = primer_nums.size();
            boolean is_primer = true;
            for(int j=0; j<size; j++){
                // if(primer_nums.elementAt(j) > i/2) // 优化下，超出一半，可判断当前数字为质数
                //     break;
                if(i % primer_nums.elementAt(j) == 0){
                    is_primer = false;
                    break;
                }
            }
            if(is_primer)
                primer_nums.add(i);
        }
        
        return primer_nums.size();
    }
}

class countPrimes {
    public static void main(String args[]){
        Integer n = 499979;
        Solution s = new Solution();
        Integer result = s.countPrimes(n);
        System.out.println(result);
    }
}