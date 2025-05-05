class Solution {
private:
    using ll = long long;
    static const int mod = 1e9 + 7;
    vector<vector<ll>> multiply(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
        vector<vector<ll>> C(3, vector<ll>(3, 0));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                ll sum = 0;
                for (int k = 0; k < 3; k++) {
                    sum = (sum + A[i][k] * B[k][j]) % mod;
                }
                C[i][j] = sum;
            }
        }
        return C;
    }

    vector<vector<ll>> power(vector<vector<ll>> base, ll exp) {
        vector<vector<ll>> result = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        while (exp > 0) {
            if (exp & 1) result = multiply(result, base);
            base = multiply(base, base);
            exp >>= 1;
        }
        return result;
    }

    public:
        int numTilings(int n) {
            if (n == 0) return 1;
            if (n == 1) return 1;
            if (n == 2) return 2;

            vector<vector<ll>> temp = {{2, 0, 1}, {1, 0, 0}, {0, 1, 0}};
            vector<vector<ll>> powered = power(temp, n - 2);
            ll answer = (powered[0][0] * 2 + powered[0][1] * 1 + powered[0][2] * 1) % mod;

            return answer;
        }
    };