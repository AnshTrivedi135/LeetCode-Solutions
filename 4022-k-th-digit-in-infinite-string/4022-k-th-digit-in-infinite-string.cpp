class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9)
            return k;

        k -= 9;

        long long digits = 2;
        long long start = 1;

        while (true) {
            long long blocks = 9 * (long long)pow(10, digits - 2);

            long long blockSize = 10 * digits;

            if (k <= blocks * blockSize)
                break;

            k -= blocks * blockSize;
            digits++;
            start *= 10;
        }

        // IMPORTANT: blockSize must be declared here too
        long long blockSize = 10 * digits;

        long long block = start + (k - 1) / blockSize;

        long long pos = (k - 1) % blockSize;

        long long index = pos / digits;

        long long num;

        if (block % 2 == 0)
            num = 10 * block + index;
        else
            num = 10 * block + 9 - index;

        string s = to_string(num);

        return s[pos % digits] - '0';
    }
};