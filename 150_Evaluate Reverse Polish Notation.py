"""
150. Evaluate Reverse Polish Notation
Use a stack to evaluate tokens in postfix order.
"""
from typing import List

def evalRPN(tokens: List[str]) -> int:
    st = []
    for t in tokens:
        if t in ('+','-','*','/'):
            b = int(st.pop()); a = int(st.pop())
            if t == '+': st.append(a+b)
            elif t == '-': st.append(a-b)
            elif t == '*': st.append(a*b)
            else: st.append(int(a / b))
        else:
            st.append(int(t))
    return st[-1]

if __name__ == '__main__':
    print("evalRPN(['2','1','+','3','*']) =", evalRPN(['2','1','+','3','*']))
    print("evalRPN(['4','13','5','/','+']) =", evalRPN(['4','13','5','/','+']))

# Time Complexity: O(n)
# Space Complexity: O(n)
