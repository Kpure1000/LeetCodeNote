//  快速幂

#include <iostream>
#include <climits>

class Solution
{
public:
    static double myPow(double x, int n)
    {
        if (x == 1.0 || x == -1.0 && (n == 0 || n == INT_MIN))
            return 1.0;
        if (x == 0.0 || n == INT_MIN)
            return 0.0;
        double re = 1.0;
        if (n > 0)
        {
            while (n > 0)
            {
                if (n & 1)
                {
                    re *= x;
                }
                x *= x;
                n /= 2;
            }
        }
        else
        {
            n = -n;
            while (n > 0)
            {
                if (n & 1)
                {
                    re *= x;
                }
                x *= x;
                n /= 2;
            }
            re = 1.0 / re;
        }
        return re;
    }
};
int main()
{
    std::cout << Solution::myPow(0.2, 10) << "\n";
}
