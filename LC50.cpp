//  快速幂

#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {
        qsort(nullptr, 10, 10, [](int a, int b)->int{
             return a <= b; 
             });
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