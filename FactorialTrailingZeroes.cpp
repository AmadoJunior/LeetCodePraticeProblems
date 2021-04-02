//Problem =========================
/*
    Given an integer n, return the number of trailing zeroes in n!.
    Follow up: Could you write a solution that works in logarithmic time complexity?
*/

//Naive Solution
//Calculating Factorial and Counting Trailing Zeroes.
//Fails Due to Overflow.
class SolutionNaive {
public:
    unsigned long getFactorialNaive(int n){
        if(n > 1){
            return n * getFactorialNaive(n - 1);
        } else {
            return 1;
        }
    }
    
    int countTrailingZeroesNaive(unsigned long n){
        int count = 0;
        while(n % 10 == 0){
            n /= 10;
            count++;
        }
        return count;
    }
    
    int trailingZeroesNaive(int n) {
        unsigned long factorial = getFactorialNaive(n);
        return countTrailingZeroesNaive(factorial);
    }
};


//Fastest Solution
/*

    -The above method can cause overflow for slightly bigger numbers as the factorial of a number is a big number (See factorial of 20 given in above examples). 
    The idea is to consider prime factors of a factorial n. A trailing zero is always produced by prime factors 2 and 5. If we can count the number of 5s and 2s,
    our task is done. Consider the following examples.
    n = 5: There is one 5 and 3 2s in prime factors of 5! (2 * 2 * 2 * 3 * 5). So a count of trailing 0s is 1.
    n = 11: There are two 5s and eight 2s in prime factors of 11! (2 8 * 34 * 52 * 7). So the count of trailing 0s is 2.
    
    - We can easily observe that the number of 2s in prime factors is always more than or equal to the number of 5s. So if we count 5s in prime factors, we are done.  
    How to count the total number of 5s in prime factors of n!? A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. It is not done yet,
    there is one more thing to consider. Numbers like 25, 125, etc have more than one 5. For example, if we consider 28! we get one extra 5 and the number of 0s 
    becomes 6. Handling this is simple, first, divide n by 5 and remove all single 5s, then divide by 25 to remove extra 5s, and so on. Following is the summarized 
    formula for counting trailing 0s.
    
*/
class Solution {
public:   
    int trailingZeroes(int n) {
        int count = 0;
        int powerOfFive = 5;
        while(powerOfFive <= n){
            count += n / powerOfFive;
            powerOfFive *= 5;
        }
        return count;
    }
};