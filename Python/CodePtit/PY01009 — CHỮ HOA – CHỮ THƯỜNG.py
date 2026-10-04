s = input()
cntThuong = 0

for x in s:
    if x.islower(): cntThuong += 1

print(s.upper() if (len(s) - cntThuong > cntThuong) else s.lower())