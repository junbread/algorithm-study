/*
 *  Problem No: 2748
 *  Date: 2019-08-11
 *  Type: Dynamic Programming 
 */
#include <iostream>

using namespace std;

long get_fibonacci(int n, long* fibonacci){
    if(fibonacci[n] != 0 || n == 0) {
        return fibonacci[n];
    }

    return fibonacci[n] = get_fibonacci(n - 1, fibonacci)
                        + get_fibonacci(n - 2, fibonacci);
}

int main() {
    int n;

    long fibonacci[91] = {0,};
    fibonacci[1] = 1;

    cin >> n;
    cout << get_fibonacci(n, fibonacci) << endl;

    return 0;
}