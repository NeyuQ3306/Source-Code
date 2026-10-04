from tokenize import endpats, group

def solve():
    with open('MONTHI.in','r',encoding='utf-8') as f:
        m_lines = [l.strip() for l in f.read().splitlines() if l.strip()]

    n = int(m_lines[0])
    subjects = {}
    idx = 1
    for _ in range(n):
        m_code = m_lines[idx]
        m_name = m_lines[idx+1]
        m_format = m_lines[idx+2]
        subjects[m_code] = m_name
        idx += 3

    with open('CATHI.in','r',encoding='utf-8') as f:
        c_lines = [l.strip() for l in f.read().splitlines() if l.strip()]

    m = int(c_lines[0])
    slots = {}
    idx = 1
    for i in range(1,m+1):
        code = f"C{i:03d}"
        date = c_lines[idx]
        time = c_lines[idx+1]
        room = c_lines[idx+2]

        d,mo,y = map(int,date.split('/'))
        h,mi = map(int,time.split(':'))

        slots[code] = (y,mo,d,h,mi,code,date,time,room)
        idx += 3

    with open('LICHTHI.in','r',encoding='utf-8') as f:
        l_lines = [l.strip() for l in f.read().splitlines() if l.strip()]

    k = int(l_lines[0])
    idx = 1
    ans = []
    for _ in range(k):
        parts = l_lines[idx].split()
        c_code = parts[0]
        m_code = parts[1]
        group = parts[2]
        sv = parts[3]

        if c_code in slots and m_code in subjects:
            y,mo,d,h,i, _, date,time,room = slots[c_code]
            m_name = subjects[m_code]
            sort_key = (y,mo,d,h,mi,c_code)
            ans.append((sort_key, f"{date} {time} {room} {m_name} {group} {sv}"))

        idx += 1

    ans.sort(key = lambda x : x[0])
    for item in ans:
        print(item[1])

if __name__ == '__main__':
    solve()
