#include <bits/stdc++.h>
using namespace std;

// Manual gcd (Euclidean algorithm)
int gcd_manual(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Manual lcm using gcd
int lcm_manual(int a, int b)
{
    return (a / gcd_manual(a, b)) * b;
}

int main()
{
    // --- Power ---
    double base = 2.0;
    double exponent = 10.0;
    double pow_result = pow(base, exponent); // 2^10 = 1024
    cout << base << "^" << exponent << " = " << pow_result << "\n";

    // --- Square root ---
    double val = 49.0;
    cout << "sqrt(" << val << ") = " << sqrt(val) << "\n";

    // --- Absolute value ---
    int i = -42;
    double d = -3.14;
    cout << "abs(int): " << abs(i) << "\n";
    cout << "fabs(double): " << fabs(d) << "\n";

    // --- Rounding functions ---
    double x = 3.75;
    cout << "ceil(" << x << ") = " << ceil(x) << "\n";   // 4
    cout << "floor(" << x << ") = " << floor(x) << "\n"; // 3
    cout << "round(" << x << ") = " << round(x) << "\n"; // 4

    // --- Logarithms and exponentials ---
    double e = 2.718281828;
    cout << "log(" << e << ") = " << log(e) << " (natural log)\n";
    cout << "log10(1000) = " << log10(1000) << "\n";
    cout << "exp(1) = " << exp(1) << "\n";

    // --- Trigonometric functions ---
    double angle = 45.0;
    double rad = angle * M_PI / 180.0; // Convert degrees to radians
    cout << "sin(" << angle << ") = " << sin(rad) << "\n";
    cout << "cos(" << angle << ") = " << cos(rad) << "\n";
    cout << "tan(" << angle << ") = " << tan(rad) << "\n";

    // --- Greatest Common Divisor (GCD) and Least Common Multiple (LCM) ---
    int a = 48, b = 180;

#if __cplusplus >= 201703L
    // Use std::gcd and std::lcm if available (C++17 and later)
    cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << "\n";
    cout << "lcm(" << a << ", " << b << ") = " << lcm(a, b) << "\n";
#else
    // Otherwise use manual implementation
    cout << "gcd_manual(" << a << ", " << b << ") = " << gcd_manual(a, b) << "\n";
    cout << "lcm_manual(" << a << ", " << b << ") = " << lcm_manual(a, b) << "\n";
#endif

    // --- Min and Max ---
    cout << "min(5, 10) = " << min(5, 10) << "\n";
    cout << "max(5, 10) = " << max(5, 10) << "\n";

    // --- Power of 2 check (bitwise trick) ---
    int num = 16;
    bool isPowerOfTwo = (num > 0) && ((num & (num - 1)) == 0);
    cout << num << " is power of two? " << (isPowerOfTwo ? "Yes" : "No") << "\n";

    // --- Integer division with ceiling ---
    int numerator = 7, denominator = 3;
    int ceilDiv = (numerator + denominator - 1) / denominator;
    cout << "Ceiling division of " << numerator << "/" << denominator << " = " << ceilDiv << "\n";

    // --- Modular exponentiation (fast power) ---
    auto modPow = [](long long base, long long exponent, long long mod) -> long long
    {
        long long result = 1;
        base %= mod;
        while (exponent > 0)
        {
            if (exponent & 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exponent >>= 1;
        }
        return result;
    };

    cout << "modPow(2, 10, 1000) = " << modPow(2, 10, 1000) << "\n"; // 2^10 % 1000 = 24

    // --- Euler's Totient function (example code for prime factorization) ---
    auto phi = [](int n) -> int
    {
        int result = n;
        for (int p = 2; p * p <= n; ++p)
        {
            if (n % p == 0)
            {
                while (n % p == 0)
                    n /= p;
                result -= result / p;
            }
        }
        if (n > 1)
            result -= result / n;
        return result;
    };

    cout << "Euler's Totient phi(36) = " << phi(36) << "\n";

    return 0;
}
