"""
N-Queens II
Count number of distinct N-Queens solutions using backtracking with bitmasks.
"""
def total_n_queens(n: int) -> int:
    count = 0
    def dfs(row, cols, diags, anti):
        nonlocal count
        if row == n:
            count += 1; return
        avail = ((1<<n)-1) & ~(cols | diags | anti)
        while avail:
            bit = avail & -avail; avail -= bit
            dfs(row+1, cols|bit, (diags|bit)<<1, (anti|bit)>>1)
    dfs(0,0,0,0)
    return count

if __name__ == '__main__':
    print('N-Queens n=4:', total_n_queens(4))
    print('N-Queens n=8:', total_n_queens(8))

# Time Complexity: roughly O(N!) with pruning
# Space Complexity: O(N)
