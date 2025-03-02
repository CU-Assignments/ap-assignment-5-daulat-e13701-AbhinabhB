class Solution {
public:
  int firstBadVersion(int n) {
    if (n == 1) {
      if (isBadVersion(1)) {
        return 1;
      } else {
        return 0;
      }
    }

    long left = 0, right = n;
    while (left <= right) {
      long mid = (left + right) / 2;
      if (isBadVersion(mid)) {
        if (!isBadVersion(mid - 1)) {
          return mid;
        } else {
          right = mid;
        }
      } else {
        if (isBadVersion(mid + 1)) {
          return mid + 1;
        } else {
          left = mid;
        }
      }
    }
    return 0;
  }
};
