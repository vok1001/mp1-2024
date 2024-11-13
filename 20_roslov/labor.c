#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


//test
int check_sort(int a[], int n){
    int i;
    for (i = 0; i < n - 1; i++){
        if(a[i] > a[i + 1]){
            return 1;
        }
    }
    return 0;
}



void list_print(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int input_list(int arr[]){
    int i;
    printf("Выбирите способ ввода массива:\n");
    printf("1. Вручную\n");
    printf("2. Рандомный массив\n");
    int type_input;
    scanf("%d", &type_input);
    while (type_input != 1 && type_input != 2){
        printf("Неверный ввод!!!\n");
        printf("Введите еще раз число: ");
        scanf("%d", &type_input);
    }
    int n;
    printf("Размер массива: ");
    scanf("%d", &n);
    while(n > 10000){
        printf("------------------------\n");
        printf("Максимальный размер массива 10000\n");
        printf("Повторите ввод\n");
        printf("------------------------\n");
        printf("Размер массива: ");
        scanf("%d", &n);
    }
    if (type_input == 1){
        printf("Ввод чисел: \n");
        for (i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
    }else{
        srand(100);
        for (i = 0; i < n; i++){
            arr[i] = rand();
        }
    }
    printf("Массив успешно создан!!!\n");
    return n;
}



void menu_print(){
    printf("------------------------\n");
    printf("Выберете действие\n");
    printf("1. Линейный поиск\n");
    printf("2. Бинарный поиск\n");
    printf("3. Сортировка пузырьком\n");
    printf("4. Сортировка подсчетом\n");
    printf("5. Сортировка слиянием\n");
    printf("6. Сортировка выбором\n");
    printf("7. Сортировка вставкой\n");
    printf("8. Сортировка быстрая\n");
    printf("9. Распечатать массив\n");
    printf("10. Ввести массив заново\n");
    printf("0. Выход\n");
    printf("Ввод: ");
    
}

void line_search(int arr[], int n, int x){
    int i, pos = -1, count = 0;
    for (i = 0; i < n; i++){
        count++;
        if (arr[i] == x){
            pos = i;
            break;
        }
    }
    if (pos != - 1){
        printf("Линейный поиск нашел число\n");
        printf("Индекс числа: %d \n", pos);
        printf("Число сравнений: %d \n", count);

    }else{
        printf("Числа нет в массиве\n");
    }
}

void binary_search(int arr[], int n, int x){
    int r = n, l = 0, count = 0;
    int pos = -1;
    while (l <= r){
        count++;
        int mid = (l + r) / 2;
        if (arr[mid] < x){
            l = mid + 1;
        }else if (arr[mid] > x){
            r = mid - 1;
        } else if(arr[mid] == x){
            pos = mid;
            break;
        }
    }
    if (pos != - 1){
        printf("Бинарный поиск нашел число\n");
        printf("Индекс числа: %d \n", pos);
        printf("Число сравнений: %d \n", count);

    }else{
        printf("Числа нет в массиве\n");
    }
}
//СОРТИРВКАИ begin
void bubble_sort(int arr[], int n){
    int left = 0, right = n - 1, i, temp, count = 0;
    clock_t start, finish;
    start = clock();
    while (left <= right){
        for (i = right; i > left; i--){
            if (arr[i - 1] > arr[i]){
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
            count++;
        }
        ++left;
        count++;
        for (i = left; i < right; i++){
            if (arr[i] > arr[i + 1]){
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
            count++;
        }
        --right;
        count++;
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
    printf("Время выполнения: %f sec\n ", duration);

}

void counting_sort(int arr[], int n){
    int a[20000], count = 0;
    int i;
    clock_t start, finish;
    start = clock();
    for (i = 0; i < 20000; i++){
        a[i] = 0;
        count++;
    }
    for (i = 0; i < n; i++){
        a[arr[i] + 10000] += 1;
        count++;
    }
    int index = 0;
    for(i = 0; i < 20000; i++){
        while (a[i] != 0){
            arr[index] = i - 10000;
            a[i]--;
            index++;
            count++;
        }
    }
    for (i = index; i < n; i++){
        arr[index] = 0;
        count++;
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
    printf("Время выполнения: %f sec\n ", duration);
}

void true_merge_sort(int arr[], int buffer[], int l, int r){
    int count = 0;
    if (l < r){
        int middle = (l + r) / 2;
        true_merge_sort(arr, buffer, l, middle);
        true_merge_sort(arr, buffer, middle + 1, r);
        int i, j;
        int k = l;
        for(i = l, j = middle + 1; i <= middle && j <= r; ){
            if (j > r || (i <= middle && arr[i] < arr[j])){
                buffer[k] = arr[i];
                ++i;
            }else{
                buffer[k] = arr[j];
                ++j;
            }
            ++k;
            count++;
        }
        for (i = l; i <= r; ++i){
            arr[i] = buffer[i];
            count++;
        }
    }
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
    
}

void merge_sort(int arr[], int n){
    int buffer[n];
    clock_t start, finish;
    start = clock();
    true_merge_sort(arr, buffer, 0, n - 1);
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Время выполнения: %f\n sec", duration);
    
}


void insert_sort(int arr[], int n){
    int i, count = 0;
    clock_t start, finish;
    start = clock();
    for (i = 1; i < n; i++){
        int x = arr[i];
        int j = i;
        while (j > 0 && arr[j - 1] > x){
            arr[j] = arr[j - 1];
            j--;
            count++;
        }
        arr[j] = x; 
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
    printf("Время выполнения: %f sec\n ", duration);
}

void selection_sort(int arr[], int n){
    int i, j, count = 0;
    clock_t start, finish;
    start = clock();
    for(i = 0; i < n; i++){
        int minum = arr[i];
        int index = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] <minum){
                index = j;
                minum = arr[j];
                count++;
            }
        } 
        if (index != i){
            int notes = arr[i];
            arr[i] = minum;
            arr[index] = notes;
            count++;
        }
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
    printf("Время выполнения: %f sec\n ", duration);
}

int partition(int arr[], int l, int r, int *count){
    int x, i, tmp;
    int less;
    x = arr[r];
    less = l;
    for (i = l; i < r; i++){
        if (arr[i] <= x){
            tmp = arr[i];
            arr[i] = arr[less];
            arr[less] = tmp;
            less++;
            *count += 1;
        }
    }
    tmp = arr[less];
    arr[less] = arr[r];
    arr[r] = tmp;
    *count += 3;
    return less;
}


void speed_sort(int arr[], int l, int r, int *count){
    if (l < r){
        int q = partition(arr, l, r, &count);
        speed_sort(arr, l, q - 1, &count);
        speed_sort(arr, q + 1, r, &count);
    }
    
}
//СОРТИРВКАИ end


int main(){
    int i;
    int arr[10000];
    int n = input_list(arr);
    int action, x;
    menu_print();
    scanf("%d", &action);
    clock_t start, finish;
    int count = 0;
    while (action != 0){
        switch (action)
        {
        case 1:
            printf("Число для поиска: ");
            scanf("%d", &x);
            printf("------------------------\n");
            line_search(arr, n, x);
            break;
        case 2:
            if(check_sort(arr, n)){
                printf("------------------------\n");
                printf("Массив неотсортиван!!!\n");
                break;
            }
            printf("Число для поиска: ");
            scanf("%d", &x);
            printf("------------------------\n");
            binary_search(arr, n, x);
            break;
            
        case 3:
            bubble_sort(arr, n);
            break;
        case 4:
            counting_sort(arr, n);
            break;
        case 5:
            merge_sort(arr, n);
            break;
        case 6:
            selection_sort(arr, n);
            break;
        case 7:
            insert_sort(arr, n);
            break;
        case 8:
            start = clock();
            speed_sort(arr,0, n - 1, &count);
            finish = clock();
            double duration = (double)(finish - start) / CLOCKS_PER_SEC;
            printf("------------------------\n");
            printf("Сортировка выполнена\n");
            printf("Количество операция: %d\n", count);
            printf("Время выполнения: %f sec\n ", duration);
            break;
        case 9:
            printf("------------------------\n");
            list_print(arr, n);
            break;
        case 10:
            printf("------------------------\n");
            input_list(arr);
            break;
        default:
            break;
        }
        menu_print();
        scanf("%d", &action);
    }  
}