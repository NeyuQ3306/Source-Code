import re

'''
Bài này Wa có thể do phải tách theo kí tự đặc biệt ko được liệt kê ở đề bài
- Thay vì tách theo delim đề bài cho thì tách theo các kí tự ko phải chữ cái và chữ số là được
- Ko phân biệt hoa thường thì convert input từng line thành lower()
'''

n = int(input())
mp = dict()

for i in range(n):
    s = input()
    tok = re.split(r'[^a-z0-9]', s.lower())

    for i in tok:
        if len(i) == 0:
            continue

        mp[i] = mp.get(i,0) + 1

res = list(mp.items())
res.sort(key = lambda x : (-x[1],x[0]))
for i in res:
    print(i[0],i[1])