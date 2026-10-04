import sys

def solve():
    data = sys.stdin.read().split()
    if not data:
        return

    iterator = iter(data)
    num = int(next(iterator))
    out = []

    for _ in range(num):
        n = int(next(iterator))
        k = int(next(iterator))
        c = [int(next(iterator)) for _ in range(n)]
        total = sum(c)

        if k == 0 or total == 0:
            out.append("0")
            continue

        def check(mid):
            if mid == 0: return True

            row = 0
            rem = 0
            for cnt in c:
                if rem > 0:
                    needed = mid - rem
                    if cnt >= needed:
                        row += 1
                        cnt -= needed
                        rem = 0
                    else:
                        rem = 0

                row += cnt // mid
                rem = cnt % mid
                if row >= k:
                    return True

            return row >= k

        low = 1
        high = total // k
        best = 0
        while low <= high:
            mid = (low + high) // 2
            if check(mid):
                best = mid
                low = mid + 1
            else:
                high = mid - 1
        out.append(str(best*k))
    sys.stdout.write("\n".join(out) + "\n")

if __name__ == '__main__':
    solve()