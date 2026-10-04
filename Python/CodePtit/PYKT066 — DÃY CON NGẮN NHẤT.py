import math
import sys


def solve():
    # Đọc toàn bộ dữ liệu từ đầu vào một cách an toàn
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    try:
        T = int(next(iterator))
    except StopIteration:
        return

    for _ in range(T):
        n = int(next(iterator))
        k = int(next(iterator))
        a = [int(next(iterator)) for _ in range(n)]

        ans = float('inf')

        # Vét cạn có cắt tỉa tối ưu
        for i in range(n):
            current_gcd = 0
            for j in range(i, n):
                if (j - i + 1) >= ans:
                    break

                current_gcd = math.gcd(current_gcd, a[j])

                if current_gcd < k:
                    break

                if current_gcd == k:
                    ans = min(ans, j - i + 1)
                    break

        if ans == float('inf'):
            print(-1)
        else:
            print(ans)


if __name__ == '__main__':
    solve()