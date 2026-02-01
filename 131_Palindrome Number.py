"""
131. Palindrome Number
Check if an integer is a palindrome without converting to string (reverse half technique).
"""

def is_palindrome(x: int) -> bool:
    if x < 0 or (x % 10 == 0 and x != 0):
        return False
    rev = 0
    while x > rev:
        rev = rev * 10 + x % 10
        x //= 10
    return x == rev or x == rev // 10

if __name__ == '__main__':
    print('isPalindrome(121) =', is_palindrome(121))
    print('isPalindrome(-121) =', is_palindrome(-121))
    print('isPalindrome(10) =', is_palindrome(10))

# Time Complexity: O(log10(x))
# Space Complexity: O(1)
