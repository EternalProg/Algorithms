#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> res(n);
        if(n == 1) {
            res[0] = k;
        }
        else {
            int msb = 0;
            // Отримуємо максимальну степінь 2, яка поміщається в k.
            for(int i = 0; i < 31; ++i) {
                if(k & (1 << i)) { // 1 << i -- це степені 2
                    msb = i;
                }
            }
            // Поміщаємо елемент із максимальною кількістю 1 на початок і остачу в наступний
            res[0] = (1 << msb) - 1;
            res[1] = k - res[0];
            // Всі інші елементи прсото заповнюємо 0
            for(int i = 2; i < n; ++i) {
                res[i] = 0;
            }
        }

        for(int i = 0; i < n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}