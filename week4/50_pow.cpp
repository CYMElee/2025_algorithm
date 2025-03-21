class Solution {
public:
    double myPow(double x, int n) {
        // Handle base cases
        if (x == 0.0) return 0.0;
        if (n == 0) return 1.0;
        
        // Convert n to long to handle INT_MIN overflow
        long exp = n;
        
        // If n is negative, invert x and make exp positive
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }
        
        double result = 1.0;
        double current_product = x;
        
        // Binary exponentiation
        while (exp > 0) {
            // If exp is odd, multiply result with current_product
            if (exp % 2 == 1) {
                result = result * current_product;
            }
            // Square the current_product
            current_product = current_product * current_product;
            // Divide exp by 2
            exp = exp / 2;
        }
        
        return result;
    }
};
