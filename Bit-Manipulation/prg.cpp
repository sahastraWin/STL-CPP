#include <iostream>
using namespace std;

int main()
{
    // ============================================================
    // __builtin_popcount — Count number of 1-bits (set bits)
    // ============================================================
    int a = 13;           // binary: 1101
    cout << "--- __builtin_popcount ---\n";
    cout << "popcount(13)  = " << __builtin_popcount(a)   << "\n"; // 3
    cout << "popcount(0)   = " << __builtin_popcount(0)   << "\n"; // 0
    cout << "popcount(255) = " << __builtin_popcount(255) << "\n"; // 8

    // For long long (use when n > 2^31)
    long long big = (1LL << 40) | (1LL << 20) | 1LL;
    cout << "popcountll(big) = " << __builtin_popcountll(big) << "\n"; // 3

    // CP trick: check power of 2
    int n = 16;
    cout << "Is 16 power of 2? " << (__builtin_popcount(n) == 1 ? "Yes" : "No") << "\n";

    // CP trick: count subsets of a bitmask (iterate all subsets)
    // Usually combined with bitmask DP

    // ============================================================
    // __builtin_clz — Count Leading Zeros
    // Equivalent to: (bits_in_type - 1) - position_of_MSB
    // ============================================================
    cout << "\n--- __builtin_clz ---\n";
    int b = 16;           // binary: 10000
    cout << "clz(16)  = " << __builtin_clz(b)  << "\n"; // 27 (32-bit int)
    cout << "clz(1)   = " << __builtin_clz(1)  << "\n"; // 31
    cout << "clz(128) = " << __builtin_clz(128)<< "\n"; // 24

    // CP trick: position of MSB (0-indexed from right)
    int msb_pos = 31 - __builtin_clz(b);
    cout << "MSB position of 16 = " << msb_pos << "\n"; // 4

    // CP trick: floor(log2(x))
    cout << "floor(log2(100)) = " << 31 - __builtin_clz(100) << "\n"; // 6

    // ============================================================
    // __builtin_ctz — Count Trailing Zeros
    // = position of lowest set bit (0-indexed)
    // ============================================================
    cout << "\n--- __builtin_ctz ---\n";
    int c = 12;           // binary: 1100
    cout << "ctz(12) = " << __builtin_ctz(c) << "\n"; // 2
    cout << "ctz(8)  = " << __builtin_ctz(8) << "\n"; // 3
    cout << "ctz(1)  = " << __builtin_ctz(1) << "\n"; // 0
    cout << "ctz(32) = " << __builtin_ctz(32)<< "\n"; // 5

    // CP trick: extract lowest set bit
    int x = 12;
    int lowest_set_bit = x & (-x);  // OR: 1 << __builtin_ctz(x)
    cout << "Lowest set bit of 12 = " << lowest_set_bit << "\n"; // 4

    // CP trick: iterate over all set bits of a mask
    cout << "Set bit positions of 22 (10110): ";
    int mask = 22; // binary: 10110
    while (mask) {
        int pos = __builtin_ctz(mask);
        cout << pos << " ";
        mask &= mask - 1; // remove lowest set bit
    }
    cout << "\n"; // 1 2 4

    // ============================================================
    // __builtin_parity — Parity of number of set bits
    // Returns 1 if odd count of 1s, 0 if even count
    // ============================================================
    cout << "\n--- __builtin_parity ---\n";
    cout << "parity(7)  = " << __builtin_parity(7)  << "\n"; // 1 (111 → 3 ones, odd)
    cout << "parity(6)  = " << __builtin_parity(6)  << "\n"; // 0 (110 → 2 ones, even)
    cout << "parity(15) = " << __builtin_parity(15) << "\n"; // 0 (1111 → 4 ones, even)

    // CP trick: XOR problems — checking if XOR of a range is odd/even set bits

    // ============================================================
    // __builtin_ffs — Find First Set bit (1-indexed, 0 means no bit)
    // ============================================================
    cout << "\n--- __builtin_ffs ---\n";
    cout << "ffs(12) = " << __builtin_ffs(12) << "\n"; // 3  (binary 1100, lowest bit at position 2 → returns 3)
    cout << "ffs(1)  = " << __builtin_ffs(1)  << "\n"; // 1
    cout << "ffs(0)  = " << __builtin_ffs(0)  << "\n"; // 0  (safe, no UB)
    cout << "ffs(8)  = " << __builtin_ffs(8)  << "\n"; // 4

    // Difference: ffs is 1-indexed, ctz is 0-indexed
    // ffs(x) == __builtin_ctz(x) + 1  (for x != 0)

    // ============================================================
    // __lg — Floor of log2(x)  [GCC extension, very clean]
    // ============================================================
    cout << "\n--- __lg ---\n";
    cout << "__lg(1)   = " << __lg(1)   << "\n"; // 0
    cout << "__lg(2)   = " << __lg(2)   << "\n"; // 1
    cout << "__lg(8)   = " << __lg(8)   << "\n"; // 3
    cout << "__lg(10)  = " << __lg(10)  << "\n"; // 3
    cout << "__lg(100) = " << __lg(100) << "\n"; // 6
    cout << "__lg(1024)= " << __lg(1024)<< "\n"; // 10

    // CP trick: Sparse Table — table size = __lg(n) + 1
    // CP trick: Check if x is in [2^k, 2^(k+1)) → __lg(x) == k

    // ============================================================
    // BONUS: Common Bit Tricks used in CP
    // ============================================================
    cout << "\n--- Bonus Bit Tricks ---\n";

    int num = 53; // binary: 110101

    // Check if k-th bit is set (0-indexed)
    int k = 2;
    cout << "Is bit " << k << " set in 53? " << ((num >> k) & 1 ? "Yes" : "No") << "\n"; // Yes

    // Set k-th bit
    int set_bit = num | (1 << k);
    cout << "After setting bit 2: " << set_bit << "\n";

    // Clear k-th bit
    int clear_bit = num & ~(1 << k);
    cout << "After clearing bit 2: " << clear_bit << "\n";

    // Toggle k-th bit
    int toggle_bit = num ^ (1 << k);
    cout << "After toggling bit 2: " << toggle_bit << "\n";

    // Check power of 2 (no builtin needed)
    cout << "Is 16 power of 2? " << ((16 & 15) == 0 ? "Yes" : "No") << "\n";

    // Turn off lowest set bit
    int turn_off = num & (num - 1);
    cout << "53 with lowest set bit turned off: " << turn_off << "\n"; // 52

    // Isolate lowest set bit
    int isolate = num & (-num);
    cout << "Lowest set bit of 53: " << isolate << "\n"; // 1

    // XOR trick: swap without temp
    int p = 5, q = 9;
    p ^= q; q ^= p; p ^= q;
    cout << "After XOR swap: p=" << p << " q=" << q << "\n"; // p=9 q=5

    // Count bits to flip A to B
    int A = 29, B = 15;
    cout << "Bits to flip " << A << " to " << B << ": "
         << __builtin_popcount(A ^ B) << "\n"; // popcount of XOR

    // Enumerate all subsets of a bitmask (classic DP trick)
    cout << "All subsets of mask 6 (110): ";
    for (int sub = 6; sub > 0; sub = (sub - 1) & 6) {
        cout << sub << " ";
    }
    cout << "\n"; // 6 4 2

    return 0;
}