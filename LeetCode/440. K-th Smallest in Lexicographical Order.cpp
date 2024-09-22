class Solution {
public:
  int countNumbers(int prefix, long long n) {
    long long current = prefix;
    long long next = prefix + 1;
    int count = 0;

    while (current <= n) {
      count += min(n + 1, next) - current;
      current *= 10;
      next *= 10;
    }

    return count;
  }

  int findKthNumber(int n, int k) {
    int curr = 1;
    --k;

    while (k > 0) {
      int count = countNumbers(curr, n);

      if (count <= k) {
        k -= count;
        ++curr;
      } else {
        curr *= 10;
        --k;
      }
    }

    return curr;
  }
};
