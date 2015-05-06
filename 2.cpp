#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> primes;
int lastn;
bool stop;

bool isPrime(int n) {
    int i = 0;
    while (primes[i] <= sqrt(n)) {
        if (n%primes[i] == 0) {
            return false;
        }
        i++;
    }
    return true;
}

void computePrimes(int n) {
    if (lastn%2==0) {
        lastn--;
    }
    for (int i = lastn ; i < n ; i=i+2) {
        if (isPrime(i) && i!=3) {
            primes.push_back(i);
        }
    }
    if (lastn < n) {
        lastn = n;
    }
}

int main() {
    int n, a, b;
    lastn = 3;
    primes.push_back(3);
    computePrimes(1000000);
    while(1) {
        n=1;
        a=0;
        b=0;
        stop = false;
        cin >> n;
        if (n==0) {
            break;
        }

        for (int i = 0 ; primes[i] < n ; i++) {
            for (int j = i ; primes[j] < n  && j < primes.size() ; j++) {
                if (primes[i] + primes[j] == n) {
                    a = primes[i];
                    b = primes[j];
                    stop = true;
                    break;
                }
            }
            if (stop) {
                break;
            }
        }

        if (a==0 && b==0) {
            cout << "Goldbach's conjecture is wrong." << endl;
        } else {
            cout << n << " = " << a << " + " << b << endl;
        }

    }
    return 0;
}

