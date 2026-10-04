import sys

# Tăng giới hạn đệ quy do cây CDQ có thể sâu tới log2(100000)
sys.setrecursionlimit(200000)


def solve():
    # Đọc toàn bộ file đầu vào một lần để tối ưu tốc độ I/O
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    ptr = 0
    # Xử lý trường hợp có nhiều test case trong một file
    while ptr < len(input_data):
        N = int(input_data[ptr])
        ptr += 1
        if N == 0:
            print(0)
            continue

        pairs = []
        for _ in range(N):
            pairs.append((int(input_data[ptr]), int(input_data[ptr + 1])))
            ptr += 2

        # Nén tọa độ (Coordinate Compression) cho trục Y
        y_vals = sorted(list(set([p[1] for p in pairs])))
        y_map = {val: i + 1 for i, val in enumerate(y_vals)}
        M = len(y_vals)

        pairs_mapped = [(p[0], y_map[p[1]]) for p in pairs]

        # Mảng dp[i] lưu độ dài dãy con tăng dài nhất kết thúc tại cặp thứ i
        dp = [1] * N

        # Cây Fenwick (BIT) và mảng version để reset nhanh trong O(1)
        bit = [0] * (M + 1)
        version = [0] * (M + 1)
        curr_version = [0]

        def update(y_idx, val):
            while y_idx <= M:
                # Nếu node này thuộc về một phiên bản cũ, ghi đè lên thay vì so sánh
                if version[y_idx] != curr_version[0]:
                    bit[y_idx] = val
                    version[y_idx] = curr_version[0]
                elif val > bit[y_idx]:
                    bit[y_idx] = val
                y_idx += y_idx & (-y_idx)

        def query(y_idx):
            res = 0
            while y_idx > 0:
                if version[y_idx] == curr_version[0]:
                    if bit[y_idx] > res:
                        res = bit[y_idx]
                y_idx -= y_idx & (-y_idx)
            return res

        # Hàm Chia để trị CDQ
        def cdq(l, r):
            if l == r:
                return

            mid = (l + r) // 2

            # 1. Giải quyết triệt để nửa trái
            cdq(l, mid)

            # 2. Tính toán cập nhật chéo từ nửa trái sang nửa phải
            left_nodes = list(range(l, mid + 1))
            right_nodes = list(range(mid + 1, r + 1))

            # Sắp xếp các chỉ số tạm thời theo X tăng dần
            left_nodes.sort(key=lambda i: pairs_mapped[i][0])
            right_nodes.sort(key=lambda i: pairs_mapped[i][0])

            # Tăng version để "làm trống" cây BIT toàn cục ngay lập tức
            curr_version[0] += 1

            p_l = 0
            for r_idx in right_nodes:
                # Cập nhật BIT với các phần tử nửa trái có X chặt chẽ nhỏ hơn X nửa phải
                while p_l < len(left_nodes) and pairs_mapped[left_nodes[p_l]][0] < pairs_mapped[r_idx][0]:
                    l_idx = left_nodes[p_l]
                    update(pairs_mapped[l_idx][1], dp[l_idx])
                    p_l += 1

                # Truy vấn DP lớn nhất có Y trái < Y phải
                res = query(pairs_mapped[r_idx][1] - 1)
                if res + 1 > dp[r_idx]:
                    dp[r_idx] = res + 1

            # 3. Giải quyết tiếp nửa phải (lúc này đã nhận đủ update từ trái)
            cdq(mid + 1, r)

        cdq(0, N - 1)
        print(max(dp))


if __name__ == '__main__':
    solve()