#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Sieve of Eratosthenes
    int n = 10000;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false, isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i] == false)
            continue;

        // j = i*i, i*i+i, i*i+2i, ...
        for (int j = i * i; j <= n; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    int num = 0;
    while (cin >> num && num != 0) {
        int left = 0;
        int sum = 0, cnt = 0;
        for (int right = 0; right < primes.size() && primes[right] <= num;
             right++) {
            sum += primes[right];

            while (sum > num) {
                sum -= primes[left++];
            }

            if (sum == num) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
