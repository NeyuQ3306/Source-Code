s = set(list(input().lower().split()))
t = set(list(input().lower().split()))

print(' '.join(sorted(s|t)))
print(' '.join(sorted(s&t)))