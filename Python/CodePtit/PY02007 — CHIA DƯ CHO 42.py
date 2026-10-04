import sys

# Bài này input có thể nằm trên nhiều dòng nên dùng sys

a = list(map(int,sys.stdin.read().split()))
st = set([x%42 for x in a])
print(len(st))
