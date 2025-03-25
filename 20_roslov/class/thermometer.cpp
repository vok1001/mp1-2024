#include <stdlib.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 

using namespace std;

typedef struct discover
{
    int day;
    int mount;
    int year;
    int hour;
    int minute;
    string specification;
    double temperature;
} discover;

bool operator==(const discover &a, const discover &b)
{   
    return (a.year == b.year && a.mount== b.mount && a.day == b.day && a.hour == b.hour && a.minute == b.minute);
}


class Thermometer{
    private:
        discover *all_info;
        int fullness;
        int size;

        void AddMemory(){
            discover *tmp = new discover[fullness+10];
                for(int i = 0; i < size; i++){
                    tmp[i] = all_info[i];
                }
                delete[] all_info;
                all_info = tmp;
                size = fullness+10;
        }

    public:
        Thermometer(int s=0){size = s; all_info = new discover[s]; fullness = 0;};
        void SetData(int year=0, int mount=0, int day=0, int series=1){
            int hour, minute;
            bool flag = true;
            if (year == 0 && mount == 0 && day==0 && series==1){
                cout << "Введите год: ";
                cin >> year;
                cout << "Введите месяц: ";
                cin >> mount;
                cout << "Введите день: ";
                cin >> day;
            }
            for (int i = 0; i < series; i++){
                cout << "Введите час: ";
                cin >> hour;
                cout << "Введите минуты: ";
                cin >> minute;
                discover notes;
                notes.year = year; notes.mount = mount; notes.day = day; notes.hour = hour; notes.minute = minute;
            
                for (int i = 0; i < fullness; i++){
                    if(notes == all_info[i]){
                        all_info[i].year = notes.year; all_info[i].mount = notes.mount; all_info[i].day = notes.day; 
                        all_info[i].hour = notes.hour; all_info[i].minute = notes.minute;
                        flag=false;
                        break;
                    }
                }
                if (flag){
                    if (size == fullness){
                        this->AddMemory();
                    }
                    all_info[fullness] = notes;
                    fullness++;
                    cout << size << " " << fullness << endl;
                }
            }
            
        }
        void GetData(){
            for (int i = 0; i < fullness; i++){
                cout << "Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
        }
        void SetObservation(){
            for (int i = 0; i < fullness; i++){
                cout << "ID:" << i+1 << "| Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
            cout << "Выбирете ID наблюдения, чтобы задать его"<<endl;
            int tmp;
            double temp;
            string notes;
            cin >> tmp;
            cout << "Добавьте описание для наблюдения" << endl;
            cin >> notes;
            cout << "Добавьте температуру для наблюдения" << endl;
            cin >> temp;
            all_info[tmp - 1].specification = notes;
            all_info[tmp - 1].temperature = temp;
            cout << "Описание добавлено!!"<<endl;

        }
        void GetTemperature(){
            for (int i = 0; i < fullness; i++){
                cout << "ID:" << i+1 << "| Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
            }
            cout << "Выбирете ID наблюдения, чтобы узнать температуру"<<endl;
            int tmp;
            cin >> tmp;
            cout << "Температура равна: " << all_info[tmp - 1].temperature << endl;
        }
        void SetSeriesObservation(int year=2015, int mount=1, int day=1){
            int series;
            cout << "Сколько задать наблюдений: ";
            cin >> series;
            SetData(year, mount, day, series);
        }
        void SearchMiddleTemperature(){
            int a;
            cout << "Выберите как хотите узнать среднюю температуру"<<endl;
            cout << "1) Своя дата" << endl;
            cout << "2) Определенный месяц" << endl;
            cout << "3) За всю история" << endl;
            cin >>a;
            int hour, minute, year, mount, day;
            double temp = 0;
            double count = 0;
            if (a == 1){
                cout << "Введите год: ";
                cin >> year;
                cout << "Введите месяц: ";
                cin >> mount;
                cout << "Введите день: ";
                cin >> day;
                for (int i = 0; i < fullness; i++)
                    if (all_info[i].year == year && all_info[i].mount == mount && all_info[i].day == day){
                        temp += all_info[i].temperature;
                        count++;
                    }
            }else if (a == 2){
                cout << "Введите месяц: ";
                    cin >> mount;
                for (int i = 0; i < fullness; i++)
                    if (all_info[i].mount == mount){
                        temp += all_info[i].temperature;
                        count++;
                    }  
            }else{
                for (int i = 0; i < fullness; i++){
                    temp += all_info[i].temperature;
                    count++;
                }
            }
            if (count > 0){
                cout << "Средняя температура: " << temp/count << endl; 
            }else{
                cout << "Нет наблюдений в этом периоде" << endl;
            }

        
        } //выбранной даты, выбранного месяца, за всю историю наблюдений
        void SearchDayNightTemp(int m = 1){
            cout << "Выбирите для какую найти температуру:" << endl;
            cout << "1) Дневную" << endl;
            cout << "2) Ночную" << endl;
            int tmp;
            double temp = 0;
            double count = 0;
            cin >> tmp;
            for (int i = 0; i < fullness; i++){
                if(tmp == 1){
                    if(all_info[i].mount == m && all_info[i].hour >= 6 && all_info[i].hour <= 21){
                        temp += all_info[i].temperature;
                        count+=1;
                    }
                }else{
                    if(all_info[i].mount == m && (all_info[i].hour < 6 || all_info[i].hour > 21)){
                        temp += all_info[i].temperature;
                        count+=1;
                    }
                }
            }
            if (count > 0){
                if(tmp == 1){
                    cout << "Средняя дневная температура равна: " << temp/count <<endl;
                }else{
                    cout << "Средняя ночная температура равна: " << temp/count <<endl;
                }
            }else{
                cout << "Нет наблюдений в этом периоде" << endl;
            }
        }
        void SaveHistory(){
            ofstream outFile("output.txt");
            if (!outFile.is_open()) {
                cout << "Не удалось открыть файл для записи: " << "output.txt" << endl;
            }
            for (int i = 0; i < fullness; i++) {
                outFile << all_info[i].year << " " << all_info[i].mount << " " << all_info[i].day << " " << 
                all_info[i].hour << " " << all_info[i].minute << " " << all_info[i].specification << " " << 
                all_info[i].temperature << endl; 
            }
            outFile.close();
        }
        void LoadHistory(){
            
            ifstream inFile("input.txt");
            string line;
            if (!inFile.is_open()) {
                cout << "Не удалось открыть файл: " << "input.txt" << endl;
              
            }
            int count = 0;
            while (std::getline(inFile, line)) {
                if (line.empty()) continue;
                // Используем stringstream для разбиения строки по пробелам
                std::istringstream iss(line);
                std::string word;

                // Разбиваем строку на слова
                vector <string> arr;
                while (iss >> word) {
                    arr.push_back(word);
                }
                if (size == fullness){
                    this->AddMemory();
                }
                all_info[fullness].year = stoi(arr[0]);
                all_info[fullness].mount = stoi(arr[1]);
                all_info[fullness].day = stoi(arr[2]);
                all_info[fullness].hour = stoi(arr[3]);
                all_info[fullness].minute = stoi(arr[4]);
                all_info[fullness].specification = arr[5];
                all_info[fullness].temperature = stod(arr[6]);
                fullness++;
                count++;
            }
            inFile.close(); 
        }

        void PrintInfo(){
            for (int i = 0; i < fullness; i++){
                cout << "Год: " << all_info[i].year << " Месяц: " << all_info[i].mount << " День: " << 
                all_info[i].day  << " Часы: " << all_info[i].hour << " Минуты: " << all_info[i].minute << endl;
                cout << "Описание: " << all_info[i].specification << endl; 
                cout << "Температура: " << all_info[i].temperature << endl; 
            }
        }

        

        

        ~Thermometer(){delete[] all_info;};
};



int main(){
    Thermometer a1(1);
    a1.LoadHistory();
    a1.PrintInfo();
    
    return 0;
}