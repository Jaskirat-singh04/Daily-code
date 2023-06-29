class Solution {
public:
    // Utility method to return sum of square of digits of n
    int numSquareSum(int n) {
        int squareSum = 0;
        while (n) {
            squareSum += (n % 10) * (n % 10);
            n /= 10;
        }
        return squareSum;
    }

    // Method to check if a number is a happy number
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = numSquareSum(slow);
            fast = numSquareSum(numSquareSum(fast));
        } while (slow != fast);
        return (slow == 1);
    }

    // Method to find the next smallest happy number
    int nextHappy(int n) {
        n++; // Increment n to start checking the next number
        while (!isHappy(n)) {
            n++;
        }
        return n;
    }
};
