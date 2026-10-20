#!/usr/bin/env python3
"""
驗證 main.cpp 是否 AC。
用法: python3 check.py [main.cpp] [testcase 目錄]
  1. 編譯 main.cpp
  2. 跑目錄下所有 *.in，與 *.out 比對（忽略行尾空白）
  3. 再對 1..99999 全部跑一次，和內建參考解比對
"""
import subprocess, sys, os, glob

SRC = sys.argv[1] if len(sys.argv) > 1 else "main.cpp"
TDIR = sys.argv[2] if len(sys.argv) > 2 else "."
BIN = "./main_bin"
TIMEOUT = 2  # 秒


def ref(n):
    """參考解：第 k 圈為 3k(k-1)+2 .. 3k(k+1)+1"""
    if n == 1:
        return (0, 0)
    k = 1
    while 3 * k * (k + 1) + 1 < n:
        k += 1
    rem = n - (3 * k * (k - 1) + 2)
    x, y = k - 1, 1
    for (dx, dy), s in zip([(-1, 1), (-1, 0), (0, -1), (1, -1), (1, 0), (0, 1)],
                           [k - 1, k, k, k, k, k]):
        t = min(rem, s)
        x += dx * t
        y += dy * t
        rem -= t
    return (x, y)


def norm(s):
    return [l.split() for l in s.strip().splitlines()]


def run(inp):
    try:
        p = subprocess.run([BIN], input=inp, capture_output=True, text=True, timeout=TIMEOUT)
    except subprocess.TimeoutExpired:
        return None, "TLE"
    if p.returncode != 0:
        return None, f"RE (exit code {p.returncode})"
    return p.stdout, None


def compare(name, inp, expected):
    out, err = run(inp)
    if err:
        print(f"[{err}] {name}")
        return False
    nums = inp.split()
    got, exp = norm(out), norm(expected)
    for i, e in enumerate(exp):
        g = got[i] if i < len(got) else ["<缺少輸出>"]
        if g != e:
            print(f"[WA] {name}: 輸入 {nums[i]} -> 期望 {' '.join(e)}，得到 {' '.join(g)}")
            return False
    if len(got) > len(exp):
        print(f"[WA] {name}: 輸出行數過多 ({len(got)} > {len(exp)})")
        return False
    print(f"[AC] {name}")
    return True


def main():
    c = subprocess.run(["g++", "-O2", "-std=c++17", "-o", BIN, SRC], capture_output=True, text=True)
    if c.returncode != 0:
        print("[CE]\n" + c.stderr)
        sys.exit(1)

    ok = True
    for fin in sorted(glob.glob(os.path.join(TDIR, "*.in"))):
        fout = fin[:-3] + ".out"
        if os.path.exists(fout):
            ok &= compare(os.path.basename(fin), open(fin).read(), open(fout).read())

    # 全範圍 1..99999 對參考解
    inp = "".join(f"{n}\n" for n in range(1, 100000))
    exp = "".join("%d %d\n" % ref(n) for n in range(1, 100000))
    ok &= compare("full_1_to_99999", inp, exp)

    # 檔尾沒有換行
    ok &= compare("no_trailing_newline", "5\n99999", "0 -1\n103 80\n")

    print("\n全部通過 ✅" if ok else "\n有測資沒過 ❌")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
