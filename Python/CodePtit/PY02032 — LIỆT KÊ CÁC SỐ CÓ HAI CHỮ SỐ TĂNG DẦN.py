s = input()
st = set()

idx = 0
while idx < len(s):
    if len(s[idx:idx+2]) > 1:
        st.add(s[idx:idx+2])
    idx += 2

res = sorted(st)
for i in res:
    print(i,end=' ')