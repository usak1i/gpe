import sys
def conv(n):
    if n == 1: return (0, 0)
    k = 1
    while 3*k*(k+1)+1 < n: k += 1           # ring k 包含 3k(k-1)+2 .. 3k(k+1)+1
    rem = n - (3*k*(k-1)+2)                  # ring 內 0-based 位置
    x, y = k-1, 1                            # ring 起點：上一圈最後一格往下
    for (dx,dy), s in zip([(-1,1),(-1,0),(0,-1),(1,-1),(1,0),(0,1)], [k-1,k,k,k,k,k]):
        t = min(rem, s); x += dx*t; y += dy*t; rem -= t
    return (x, y)
for line in sys.stdin:
    if line.strip(): print(*conv(int(line)))
