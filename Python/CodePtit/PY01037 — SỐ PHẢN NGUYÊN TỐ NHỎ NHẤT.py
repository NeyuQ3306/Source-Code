import bisect
import sys

# Khởi tạo hcn_list và giới hạn sinh số (20 triệu là quá đủ vì X <= 10^7)
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23]
hcn_list = []
MAX_VAL = 20000000


def generate(idx, current_val, current_divisors, limit_power):
    if current_val > 0:
        hcn_list.append((current_val, current_divisors))

    if idx == len(primes):
        return

    p = primes[idx]
    val = current_val
    for pwr in range(1, limit_power + 1):
        if val > MAX_VAL // p:
            break
        val *= p
        generate(idx + 1, val, current_divisors * (pwr + 1), pwr)


# Sinh mảng số phản nguyên tố
generate(0, 1, 1, 30)
hcn_list.sort()

# Lọc các số phản nguyên tố thực sự
real_hcn = []
max_div = 0
for val, divs in hcn_list:
    if divs > max_div:
        real_hcn.append(val)
        max_div = divs


# Tối ưu IO: Đọc luồng dữ liệu thay vì lưu hết vào RAM để tránh MLE
def solve():
    def get_tokens():
        for line in sys.stdin:
            for token in line.split():
                yield int(token)

    tokens = get_tokens()

    try:
        t = next(tokens)
    except StopIteration:
        return

    for _ in range(t):
        x = next(tokens)
        idx = bisect.bisect_left(real_hcn, x)
        # In trực tiếp ra console, không lưu mảng result lớn
        sys.stdout.write(str(real_hcn[idx]) + '\n')


if __name__ == "__main__":
    solve()