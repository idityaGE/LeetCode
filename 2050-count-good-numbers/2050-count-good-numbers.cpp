#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    int countGoodNumbers(long long n) {
        ll even = (n + 1) / 2;
        ll odd = n / 2;

        ll evenWays = power(5, even);
        ll oddWays = power(4, odd);

        return (evenWays * oddWays) % mod;
    }

    ll power(ll base, ll power) {
        ll result = 1;
        base %= mod;

        while (power > 0) {
            if (power % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            power /= 2;
        }
        return result;
    }
};