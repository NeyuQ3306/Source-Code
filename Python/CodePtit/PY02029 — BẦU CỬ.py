from collections import Counter

n, m = map(int, input().split())
a = list(map(int, input().split()))

# Đếm và sort giảm dần theo tần suất, tăng dần theo giá trị
mp = Counter(a)
# Sắp xếp ra list các tuple: (value, frequency)
thislist = sorted(mp.items(), key=lambda x: (-x[1], x[0]))

# Nếu chỉ có 1 loại phần tử hoặc tất cả các phần tử có tần suất y hệt nhau -> Không có phần tử thỏa mãn
if len(thislist) <= 1 or thislist[0][1] == thislist[-1][1]:
    print('NONE')
else:
    # Tìm tần suất đứng sau tần suất lớn nhất (tần suất của phần tử thứ 2 từ trên xuống)
    max_freq = thislist[0][1]
    second_freq = None

    for val, freq in thislist:
        if freq < max_freq:
            second_freq = freq
            break

    # In ra tất cả các giá trị có tần suất bằng second_freq (hoặc chỉ lấy giá trị đầu tiên tùy đề bài)
    for val, freq in thislist:
        if freq == second_freq:
            print(val)
            break