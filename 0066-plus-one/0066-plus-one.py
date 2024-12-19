from typing import List

class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        carry = 1
        n = len(digits)

        i = n - 1
        while i >= 0 and carry:
            digits[i] += carry
            if digits[i] == 10:
                digits[i] = 0
                carry = 1
            else:
                carry = 0
            i -= 1
        
        if carry:
            digits.insert(0, 1)
        
        return digits
