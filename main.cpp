#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    // ===== ЗАДАНИЕ 1 =====
    cout << "=== ЗАДАНИЕ 1 ===\n";
    int g; double a;
    cout << "Гости: "; cin >> g;
    cout << "Площадь: "; cin >> a;

    if (g <= 0 || a <= 0) cout << "Ошибка\n";
    else if (a / g < 8) cout << "Не подходит: мало кв.м/гостя\n";
    else if (g > 4 && a < 45) cout << "Не подходит: >4 гостей, нужно >=45 кв.м\n";
    else cout << "Подходит\n";

    // ===== ЗАДАНИЕ 2 =====
    cout << "\n=== ЗАДАНИЕ 2 ===\n";
    int n, w, r; double p;
    cout << "Ночи (1-30): "; cin >> n;
    cout << "Цена: "; cin >> p;
    cout << "Выходной (1/0): "; cin >> w;
    cout << "Постоянный (1/0): "; cin >> r;

    if (n < 1 || n > 30 || p <= 0) cout << "Ошибка\n";
    else {
        if (w) p *= 1.2;
        double t = p * n;
        double d = max(n >= 7 ? 0.1 : 0.0, r ? 0.05 : 0.0);
        t *= (1 - d);
        cout << fixed << setprecision(2) << "Итого: " << t << "\n";
    }

    // ===== ЗАДАНИЕ 3 =====
    cout << "\n=== ЗАДАНИЕ 3 ===\n";
    char c; int g2, n2;
    cout << "Код (S/D/F): "; cin >> c;
    cout << "Гости: "; cin >> g2;
    cout << "Ночи: "; cin >> n2;

    double pr = 0; int cap = 0;
    switch (toupper(c)) {
        case 'S': pr = 40; cap = 1; break;
        case 'D': pr = 65; cap = 2; break;
        case 'F': pr = 95; cap = 4; break;
    }
    if (!pr || n2 <= 0 || g2 > cap) cout << "Ошибка\n";
    else cout << "Стоимость: " << fixed << setprecision(2) << pr * n2 << "\n";

    // ===== ЗАДАНИЕ 4 =====
    cout << "\n=== ЗАДАНИЕ 4 ===\n";
    char c2; int n3, g3, w2, bf;
    cout << "Код (S/D/F): "; cin >> c2;
    cout << "Ночи: "; cin >> n3;
    cout << "Гости: "; cin >> g3;
    cout << "Выходной (1/0): "; cin >> w2;
    cout << "Завтрак (1/0): "; cin >> bf;

    double pr2 = 0; int cap2 = 0;
    switch (toupper(c2)) {
        case 'S': pr2 = 40; cap2 = 1; break;
        case 'D': pr2 = 65; cap2 = 2; break;
        case 'F': pr2 = 95; cap2 = 4; break;
    }
    if (!pr2 || n3 <= 0 || g3 > cap2) cout << "Ошибка\n";
    else {
        if (w2) pr2 *= 1.15;
        double room = pr2 * n3;
        if (n3 >= 5) room *= 0.92;

        double bfCost = 0;
        if (bf) {
            if (toupper(c2) == 'F' && n3 >= 7) bfCost = 0;
            else bfCost = 7.0 * g3 * n3;
        }

        cout << fixed << setprecision(2);
        cout << "Номер: " << room << "\n";
        cout << "Завтрак: " << bfCost << "\n";
        cout << "Итого: " << room + bfCost << "\n";
    }
    return 0;
}