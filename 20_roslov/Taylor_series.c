#include <stdio.h>
#include <stdlib.h>


typedef double(*First)(double);
typedef double(*Next)(int, double);


#define print(a) printf("%lf\n", (a))
#define forik(a) for(int i = 0; i < a; i++)

void menu_print(int *action){
    printf("Выбирите действие:\n");
    printf("1) Однократный расчет функции в заданной точке\n");
    printf("2) Серийный эксперимент.\n");
    scanf("%d", action);
}

void change_func(int *type_func){
    printf("Выбирите функцию:\n");
    printf("1) Косинус\n");
    printf("2) Синус\n");
    printf("3) Экспонент\n");
    printf("4) Секус\n");
    scanf("%d", type_func);
}

void change_x(int *x){
    printf("Введите значение x:\n");
    scanf("%lf", x);
}

void accuracy(int *eps){
    printf("Введите точность вычислений:\n");
    scanf("%lf", eps);
}

void input_n(int *n){
    printf("Введите значение N:\n");
    scanf("%d", n);
}

double FirstSin(double x){
    return x;
}

double FirstCos(double x){
    return 1;
}

double FirstExp(double x){
    return 1;
}

double NextSin(int i, double x){
    return -x * x / (2 * i) / (2 * i + 1);
}

double NextExp(int i, double x){
    return x / (i);
}

double NextCos(int i, double x){
    return  -x * x / (2 * i) / (2 * i - 1);
}

double Teylor(double x, int n, First f, Next g){
    double summ = f(x);
    double elem = x;
    double prew = f(x);
    for (int i = 1; i < n; i++){
        elem = prew * g(i, x);
        summ += elem;
        prew = elem;
        printf("%lf\n", elem); 
    }
    return summ;
}

int main(){
    int action, n, type_func;
    double x, eps;
    menu_print(&action);
    while (action != 1 && action != 2)
    {
        printf("Неправильный ввод\n");
        printf("Повторите ввод\n");
        menu_print(&action);
    }
    if (action == 1){

        change_func(&type_func);
        while (type_func != 1 && type_func != 2 && type_func != 3 && type_func != 4)
            {
                printf("Неправильный ввод\n");
                printf("Повторите ввод\n");
                change_func(&type_func);
            }
        if (type_func == 3){
            
            // change_func(&type_func);
            
            // accuracy(&eps);
            // while (eps > 0.0 && eps < 0.000001)
            // {
            //     printf("Неправильный ввод\n");
            //     printf("Повторите ввод\n");
            //     accuracy(&eps);
            // }
            input_n(&n);
            change_x(&x);
            // while (n > 0 && n < 1000)
            // {
            //     printf("Неправильный ввод\n");
            //     printf("Повторите ввод\n");
            //     input_n(&n);
            // }  
            double y = Teylor(x, n, FirstExp, NextExp);
            printf("%lf", y);
        }else if (type_func == 1){
            input_n(&n);
            change_x(&x);
            double y = Teylor(x, n, FirstCos, NextCos);
            printf("%lf", y);
        }else if (type_func == 2){
            input_n(&n);
            change_x(&x);
            double y = Teylor(x, n, FirstSin, NextSin);
            printf("%lf", y);
        }
    }else if (action == 1){
        // change_func(&type_func);
        // while (type_func != 1 && type_func != 2 && type_func != 3)
        // {
        //     printf("Неправильный ввод\n");
        //     printf("Повторите ввод\n");
        //     change_func(&type_func);
        // }
        // accuracy(&eps);
        // while (eps > 0.0 && eps < 0.000001)
        // {
        //     printf("Неправильный ввод\n");
        //     printf("Повторите ввод\n");
        //     accuracy(&eps);
        // }
        input_n(&n);
        scanf("%lf", &x);
        // while (n > 0 && n < 1000)
        // {
        //     printf("Неправильный ввод\n");
        //     printf("Повторите ввод\n");
        //     input_n(&n);
        // }  
        // double y = Teylor(x, n, FirstCos, NextCos);
        // printf("%lf", y);
    }
}