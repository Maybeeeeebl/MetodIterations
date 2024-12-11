#include <iostream>
#include <cmath>

using namespace std;

// Функция для итерационного процесса
double phi(double x) 
{
    // acos(x) - sqrt(1 - 0.3 * pow(x, 3));
    // acos(x)=sqrt(1 - 0.3 * pow(x, 3)) 
    // x=cos(sqrt(1 - 0.3 * pow(x, 3)))
    // phi(x) = cos(sqrt(1 - 0.3 * pow(x, 3)))
    return cos(sqrt(1 - 0.3 * pow(x, 3))); 
}

// Метод итераций
double IterationMethod(double x0, double tol, int maxIterations)
{
    double x_prev = x0;
    double x_next = phi(x_prev);
    int iterations = 0;
    cout << "Итерация 0: x = " << x_prev << endl;
    while (abs(x_next - x_prev) > tol && iterations < maxIterations)
    {
        x_prev = x_next;
        x_next = phi(x_prev);
        iterations++;
        cout << "Итерация " << iterations << ": x = " << x_next << endl;
    }

    if (iterations >= maxIterations) 
    {
        cout << "слишком много итераций" << endl;
    }

    cout << "Кол-во итераций: " << iterations << endl;
    return x_next;
}

double truncate(double value, int decimalPlaces) // функция для сокращения числа на 4 символа
{
    double factor = pow(10, decimalPlaces);
    return trunc(value * factor) / factor;
}

int main() 
{
    setlocale(LC_ALL, "ru");
    double x0 = 0.5;          // случайно выбранная точка на интервале
    double tol = 1e-6;  // точность
    int maxIterations = 100;  // Макс число итераций
    double root = IterationMethod(x0, tol, maxIterations); // вызов метода
    root = truncate(root, 4); // ограничение по 4 символам после запятой
    cout << "Корень уравнения: x = " << root << endl;
    return 0;
}
