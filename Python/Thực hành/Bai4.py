from collections import deque

N = 4
def read_state():
    state = 0
    for i in range(4):
        row = input().strip()
        for j in range(4):
            if row[j] == '1':
                pos = i*4 + j
                state |= (1<<pos)
    return state

start = read_state()
target = read_state()

if start.bit_count() != target.bit_count():
    print(-1)
    exit()

dx = [-1,1,0,0]
dy = [0,0,-1,1]

move = [None] * (1<<16)
parent = [-1] *  (1<<16)
visited = [False] * (1<<16)
q = deque()
q.append(start)
visited[start] = True

while q:
    state = q.popleft()
    if start == target:
        break
    for pos in range(16):
        if(state & (1<<pos)) == 0:
            continue
        u = pos // 4
        v = pos % 4

        for k in range(4):
            x = u + dx[k]
            y = v + dy[k]

            if x<0 or x>=4 or y<0 or y>=4:
                continue

            new_pos = x*4 +y
            if state & (1<<new_pos):
                continue
            new_state = state
            new_state &= ~(1<<pos)
            new_state |= (1<<new_pos)

            if not visited[new_state]:
                visited[new_state] = True
                parent[new_state] = state

                move[new_state] = (u+1,v+1,x+1,y+1)
                q.append(new_state)
if not visited[target]:
    print(-1)
else:
    ans = []
    cur = target
    while cur != target:
        ans.append(move[cur])
        cur = parent[cur]
    ans.reverse()
    print(len(ans))
    for u,v,x,y in ans:
        print(u,v,x,y)
