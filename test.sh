#!/usr/bin/env bash
# Usage: ./test.sh [problem-dir ...]
# Compiles each problem's main.cpp and checks `cat input*.txt | ./main` against output*.txt.
# With no arguments, tests the current problem if run from inside one (e.g. `../test.sh`),
# otherwise every problem directory.

orig_dir="$PWD"
cd "$(dirname "$0")" || exit 1
root_dir="$PWD"

if [ $# -gt 0 ]; then
    dirs=("$@")
elif [ "$(dirname "$orig_dir")" = "$root_dir" ]; then
    dirs=("$(basename "$orig_dir")")
else
    dirs=()
    for d in */; do dirs+=("${d%/}"); done
fi

pass=0
fail=0

for dir in "${dirs[@]}"; do
    dir="${dir%/}"
    if [ ! -f "$dir/main.cpp" ]; then
        echo "[SKIP] $dir: no main.cpp"
        continue
    fi

    if ! (cd "$dir" && g++ main.cpp -o main); then
        echo "[FAIL] $dir: compile error"
        fail=$((fail + 1))
        continue
    fi

    found=0
    for input in "$dir"/input*.txt; do
        [ -f "$input" ] || continue
        suffix="${input##*/input}"
        expected="$dir/output$suffix"
        name="$dir/input$suffix"
        if [ ! -f "$expected" ]; then
            echo "[SKIP] $name: no output$suffix"
            continue
        fi
        found=1

        actual=$(mktemp)
        (cd "$dir" && cat "input$suffix" | ./main) > "$actual"
        if diff -u "$expected" "$actual" > /dev/null; then
            echo "[PASS] $name"
            pass=$((pass + 1))
        else
            echo "[FAIL] $name"
            awk '
                FILENAME == ARGV[1] {
                    output[++output_count] = $0
                    if (length($0) > output_width) output_width = length($0)
                    next
                }
                {
                    expected[++expected_count] = $0
                    if (length($0) > expected_width) expected_width = length($0)
                }
                END {
                    if (output_width < 6) output_width = 6
                    if (expected_width < 8) expected_width = 8
                    border = "+-"
                    for (i = 0; i < output_width; i++) border = border "-"
                    border = border "-+-"
                    for (i = 0; i < expected_width; i++) border = border "-"
                    border = border "-+"
                    print border
                    printf "| %-*s | %-*s |\n", output_width, "Output", expected_width, "Expected"
                    print border
                    count = output_count > expected_count ? output_count : expected_count
                    for (i = 1; i <= count; i++)
                        printf "| %-*s | %-*s |\n", output_width, output[i], expected_width, expected[i]
                    print border
                }
            ' "$actual" "$expected"
            fail=$((fail + 1))
        fi
        rm -f "$actual"
    done

    [ $found -eq 1 ] || echo "[SKIP] $dir: no input/output pair"
done

echo
echo "Passed: $pass, Failed: $fail"
[ $fail -eq 0 ]
