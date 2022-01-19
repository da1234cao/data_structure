

class Solution {
    public int isPrimerNumber(int n) {
        int up_bounder = n/2;
        for(int i=2; i<=up_bounder; i++){
            if(n%i == 0)
                return 0;
        }
        return 1;
    }

    public int countPrimes(int n) {
        if(n<=1) // 0和1的质数为零。题目限定n为非负整数
            return 0;

        int result=0;
        for(int i=2; i<n; i++)
            result += isPrimerNumber(i);
        
        return result;
    }
}