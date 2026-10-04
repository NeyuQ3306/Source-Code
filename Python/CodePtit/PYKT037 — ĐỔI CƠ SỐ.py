import string

def convert_base(n, b):
    if n == 0:
        return "0"
    # Tập hợp các ký tự gồm 10 chữ số (0-9) và 26 chữ cái in hoa (A-Z)
    chars = string.digits + string.ascii_uppercase
    res = []

    while n > 0:
        res.append(chars[n % b])
        n //= b

    return "".join(reversed(res))


def main():
    t = int(input())
    for _ in range(t):
        n, b = map(int, input().split())
        print(convert_base(n, b))


if __name__ == "__main__":
    main()