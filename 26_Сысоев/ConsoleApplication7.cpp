#include <iostream>
#include <cmath>
using namespace std;

class Funct {
public:
    virtual double value(double x) = 0;
    virtual double derivative(double x) = 0;

    void print(double a, double b, double h) {
        for (double x = a; x <= b; x += h) {
            cout << "f(" << x << ") = " << value(x) << endl;
        }
    }

    virtual ~Funct() {}
};

class Func1 : public Funct {
public:
    double value(double x) {
        return x * x - 9;
    }

    double derivative(double x) {
        return 2 * x;
    }
};

class Func2 : public Funct {
public:
    double value(double x) {
        return cos(x) - x;
    }

    double derivative(double x) {
        return -sin(x) - 1;
    }
};

class Method {
public:
    virtual double next(double x) = 0;
    virtual void setFunction(Funct* f) = 0;
    virtual void reset(double x0) {}
    virtual ~Method() {}
};

class NewtonMethod : public Method {
    Funct* func;

public:
    void setFunction(Funct* f) {
        func = f;
    }

    double next(double x) {
        return x - func->value(x) / func->derivative(x);
    }
};

class SecantMethod : public Method {
    Funct* func;
    double x_prev;
    double x_curr;
    bool first_call;

public:
    void setFunction(Funct* f) {
        func = f;
    }

    void reset(double x0) {
        x_curr = x0;
        x_prev = x0 - 0.01; 
        first_call = true;
    }

    double next(double x) {
        double fx = func->value(x_curr);
        double fx_prev = func->value(x_prev);

        if (fabs(fx - fx_prev) < 1e-12) {
            cout << "Ошибка: деление на ноль в методе секущих\n";
            return x_curr;
        }

        double x_next = x_curr - fx * (x_curr - x_prev) / (fx - fx_prev);

        x_prev = x_curr;
        x_curr = x_next;

        return x_next;
    }
};

class Solver {
    Funct* func;
    Method* method;

public:
    Solver(Funct* f, Method* m) {
        func = f;
        method = m;
        method->setFunction(func);
    }

    void solve(double x0, double eps) {
        method->reset(x0);
        double x = x0;
        double x_next;
        do {
            x_next = method->next(x);
            cout << "x = " << x_next << endl;
            if (fabs(x_next - x) < eps) {
                break;
            }
            x = x_next;
        } while (true);

        cout << "Корень найден: x = " << x_next << endl;
    }
};

int main() {
    setlocale(LC_ALL, "ru-RU");

    Funct* func = NULL;
    Method* method = NULL;

    int func_choice, method_choice;
    double x0, eps;

    cout << "Выберите функцию: \n1. x^2 - 9 \n2. cos(x) - x \n> ";
    cin >> func_choice;

    if (func_choice == 1)
        func = new Func1();
    else if (func_choice == 2)
        func = new Func2();
    else {
        cout << "Неверный выбор функции \n";
        return 1;
    }

    cout << "Выберите метод: \n1. Метод Ньютона \n2. Метод секущих \n> ";
    cin >> method_choice;

    if (method_choice == 1)
        method = new NewtonMethod();
    else if (method_choice == 2)
        method = new SecantMethod();
    else {
        cout << "Неверный выбор метода \n";
        return 1;
    }

    cout << "Введите начальное x0: ";
    cin >> x0;

    cout << "Введите точность eps: ";
    cin >> eps;

    Solver solver(func, method);
    solver.solve(x0, eps);

    delete func;
    delete method;

    return 0;
}
