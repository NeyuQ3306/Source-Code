a = input()
b = input()

idxa,idxb = 0,0
for i in range(len(a)):
    if a[i] != '0':
        idxa = i
        break

for i in range(len(b)):
    if b[i] != '0':
        idxb = i
        break

c = int(a[idxa:]) - int(b[idxb:])
print(c)