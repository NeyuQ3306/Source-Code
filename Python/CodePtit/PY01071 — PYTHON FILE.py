s = input().lower()
print('yes' if s[len(s)-3:] == '.py' else 'no')