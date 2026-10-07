import re
import sys

# sys.stdin = open('inputTest.txt')
input_data = sys.stdin.read().lower().strip()
res = []
sentences = re.split(r'[.?!]+',input_data)

for sen in sentences:
    if len(sen) == 0: continue
    sen = ' '.join(sen.strip().split())
    res.append(sen[0].upper() + sen[1:])

for i in res:
    print(i)