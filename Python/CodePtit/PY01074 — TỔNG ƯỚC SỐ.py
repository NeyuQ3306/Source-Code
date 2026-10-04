'''
Bài này sàng biến đổi bị tle, cách làm là tính ước ngto nhỏ nhất của
mỗi số n và khi tính tổng ước ta chia liên tiếp cho ước ngto nhỏ nhất
cho tới khi n về 1

- C++: sàng biến đổi AC
- Java: Tìm ước ngto nhỏ nhất + hàm tổng ước AC
- Python: Phải tính tổng ước ngay trong hàm ước ngto nhỏ nhất mới AC

Dùng thêm sys để đọc tối ưu vẫn tle =)))) chịu r
'''


from sys import stdin

untnn = [0] * (2*10**6+1)
def sang():
    # tính untnn của số i
    for i in range(2, 2 * 10 ** 6 + 1):
        if untnn[i] == 0:
            for j in range(i, 2 * 10 ** 6 + 1, i):
                # tránh ghi đè untnn, vd 6 = 2*3 nếu ko xét if sẽ ghi đè = 3
                if untnn[j] == 0:
                    untnn[j] = i

    # DP: tổng ước của i = ước ngto nn của i + tổng ước của i//untnn[i]
    # ghi đè luôn lên mảng untnn

    for i in range(2,2*10**6+1):
        tmp = untnn[i]
        if i // tmp > 1:
            untnn[i] = tmp + untnn[i//tmp]
        else: untnn[i] = tmp

if __name__ == "__main__":
    sang()
    n,s = int(stdin.readline()), 0
    while 1:
        try:
            x = int(stdin.readline())
            s += untnn[x]
        except: break
    print(s)
