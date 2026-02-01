"""
132. Plus One
Add one to a large integer represented as an array of digits.
"""
from typing import List

def plus_one(digits: List[int]) -> List[int]:
    n = len(digits)
    for i in range(n-1, -1, -1):
        if digits[i] < 9:
            digits[i] += 1
            return digits
        digits[i] = 0
    return [1] + digits

if __name__ == '__main__':
    print('plusOne([1,2,3]) =', ''.join(map(str, plus_one([1,2,3]))))
    print('plusOne([9,9,9]) =', ''.join(map(str, plus_one([9,9,9]))))

# Time Complexity: O(n)
# Space Complexity: O(1) (amortized)
