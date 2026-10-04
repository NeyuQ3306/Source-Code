import sys
sys.setrecursionlimit(2000)

mod = 10**9 + 7
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    N = int(input_data[0])
    b = input_data[1] if len(input_data) > 1 else ""
    total_ways = 0
    for M in range(1,16):
        min_len = 0
        for x in range(1,M+1):
            min_len += len(bin(x))[2:]
        if min_len > N:
            break
        full_mask = (1<<M) - 1
        memo = {}
        def dp(idx,mask):
            if mask == full_mask:
                return  1
            if idx >= N:
                return 0
            state = (idx,mask)
            if state in memo:
                return memo[state]

            ans = dp(idx+1,mask)
            val = 0
            for j in range(idx,N):
                val = (val<<1) | int(b[j])
                if val > M:
                    break
                if 1 <= val <= M and not (mask & (1<<(val-1))):
                    ans = (ans +dp(j+1,mask|(1<<(val-1)))) % mod
            memo[state]=ans
            return ans
        total_ways = (total_ways+dp(0,0)) % mod
    print(total_ways%mod)

if __name__ == '__main__':
    solve()
