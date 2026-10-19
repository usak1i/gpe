# GPE problem and solutions

## Problems

| Problem | UVa |
| --- | --- |
| [A mid-summer night’s dream](./A-mid-summer-night%E2%80%99s-dream) | 10057 |
| [Bachet's Game](./Bachet's-Game) | 10404 |
| [Conformity](./Conformity) | [11286](https://onlinejudge.org/external/112/11286.pdf) |
| [Digit Primes](./Digit-Primes) | [10533](https://onlinejudge.org/external/105/10533.pdf) |
| [Dollars](./Dollars) | 147 |
| [Hay Points](./Hay-Points) | 10295 |
| [Light, more light](./Light,more-light) | 10110 |
| [Longest Common Subsequence](./Longest-Common-Subsequence) | [10405](https://onlinejudge.org/external/104/10405.pdf) |
| [Longest Increasing Subsequence](./Longest-Increasing-Subsequence) | — |
| [Minesweeper](./Minesweeper) | 10189 |
| [Minimum Path Sum](./Minimum-Path-Sum) | — |
| [Oil Deposits](./Oil-Deposits) | 572 |
| [Perfection](./perfection) | 382 |
| [Quirksome Squares](./Quicksome-Squares) | [256](https://onlinejudge.org/external/2/256.pdf) |
| [Robot Instructions](./robot-instructions) | 12503 |
| [Sum of Consecutive Prime Numbers](./Sum-of-Consecutive-Prime-Numbers) | 1210 |
| [The jackpot](./The-jackpot) | 10684 |

`—` indicates that the UVa problem number has not been confirmed.

## Testing

Requires Bash and `g++`. Each problem directory should contain `main.cpp` and
matching input/output files, such as `input.txt` / `output.txt` or
`input1.txt` / `output1.txt`.

```bash
./test.sh                 # test all problems
./test.sh Dollars         # test specific problems
cd Dollars && ../test.sh  # test the current problem
```

The script compiles each solution and reports `[PASS]`, `[FAIL]`, or `[SKIP]`,
followed by the total passed and failed counts. Failed comparisons display the
actual `Output` and `Expected` output side by side:

```text
+--------+----------+
| Output | Expected |
+--------+----------+
| 12     | 13       |
+--------+----------+
```

Comparisons are exact, including spaces and newline characters. The table does
not make every whitespace difference visible: a missing final newline can cause
`[FAIL]` even when both columns look identical. End each result line with `\n`,
for example `cout << "Losing streak.\n";` in The jackpot.

The script exits with status `1` if any compilation or comparison fails, and `0`
otherwise. Skipped cases do not count as failures.
