class CaThi:
    def __init__(self,idx,date,time,room):
        self.id = f"C{idx:03d}"
        self.date = date
        self.time = time
        self.room = room

        d,m,y = map(int,date.split('/'))
        h,mi = map(int,time.split(':'))

        self.sort_key = (y,m,d,h,mi,idx)

    def __lt__(self, other):
        return self.sort_key < other.sort_key

    def __str__(self) -> str:
        return f"{self.id} {self.date} {self.time} {self.room}"

def solve():
    with open('CATHI.in','r',encoding='utf-8-sig') as f:
        lines = [l.strip() for l in f.read().splitlines() if l.strip()]

    n = int(lines[0])
    exams = []
    idx = 1

    for i in range(1,n+1):
        if idx + 2 < len(lines):
            exams.append(CaThi(i,lines[idx],lines[idx+1],lines[idx+2]))
            idx += 3

    exams.sort()
    for exam in exams:
        print(exam)

if __name__ == '__main__':
    solve()
