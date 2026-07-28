class Solution:
    def numberOfWays(self, s: str) -> int:
        total_zeros = s.count('0')
        total_ones = len(s) - total_zeros
        
        left_zeros = 0
        left_ones = 0
        ans = 0
        
        for char in s:
            if char == '0':
                right_ones = total_ones - left_ones
                ans += left_ones * right_ones
                left_zeros += 1
            else:
                right_zeros = total_zeros - left_zeros
                ans += left_zeros * right_zeros
                left_ones += 1
                
        return ans