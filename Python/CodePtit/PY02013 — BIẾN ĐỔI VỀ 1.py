import sys
from collections import deque

while True:
    n = int(input())
    if n == 0: sys.exit()
    if n == 1:
        print(1)
    else:
        st = {n}
        while n != 1:
            if n%2 == 0:
                n //= 2
                st.add(n)
            else:
                n = n*3 + 1
                st.add(n)

        print(len(st))