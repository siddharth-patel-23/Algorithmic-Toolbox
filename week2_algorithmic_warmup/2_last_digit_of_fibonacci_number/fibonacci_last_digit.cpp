#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int a = 0;
    int b  = 1;

    for (int i = 2; i <= n; ++i) {
        int tmp=b%10;
        b=(a+b)%10;
        a=tmp%10;
    }

    return b % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << '\n';
    }
