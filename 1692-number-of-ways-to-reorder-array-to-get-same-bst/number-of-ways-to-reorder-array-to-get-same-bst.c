#define MOD 1000000007
long long comb[1001][1001];

long long solve(int *nums, int n) {
    if (n <= 2)
        return 1;

    int left[1001], right[1001];
    int l = 0, r = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] < nums[0])
            left[l++] = nums[i];
        else
            right[r++] = nums[i];
    }

    long long ans = comb[n - 1][l];
    ans = ans * solve(left, l) % MOD;
    ans = ans * solve(right, r) % MOD;

    return ans;
}
int numOfWays(int* nums, int numsSize) {
    for (int i = 0; i <= numsSize; i++) {
        comb[i][0] = comb[i][i] = 1;

        for (int j = 1; j < i; j++) {
            comb[i][j] =
                (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    return (solve(nums, numsSize) - 1 + MOD) % MOD;
}